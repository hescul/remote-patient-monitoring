package com.hescul.urgent.ui.screens.home.doctor

import android.content.Context
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateMapOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.hescul.urgent.R
import com.hescul.urgent.core.cognito.CognitoAuthenticator
import com.hescul.urgent.core.mqtt.doctor.Doctor
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch

class DoctorViewModel : ViewModel() {
    val doctorAttributes = mutableStateMapOf<String, String>()

    var isLaunched by mutableStateOf(false)
        private set
    var isProgressing by mutableStateOf(false)
        private set
    var status by mutableStateOf("")
        private set
    var isStatusError by mutableStateOf(false)
        private set
    var showSignOutAlertDialog by mutableStateOf(false)
        private set


    private fun setStatus(message: String = "", isError: Boolean = false) {
        status = message
        isStatusError = isError
    }

    fun onLaunch(context: Context) {
        isProgressing = true
        val fetchAttributesJob = viewModelScope.launch(Dispatchers.IO) {
            requestUserAttribute(context)
        }
        fetchAttributesJob.invokeOnCompletion { isLaunched = true }
    }

    private fun requestUserAttribute(context: Context) {
        setStatus(FETCH_ATTRIBUTES_MESSAGE)
        val userId = CognitoAuthenticator.getCurrentUserId(context)
        if (userId != null) {
            CognitoAuthenticator.requestUserAttributes(
                context = context,
                userId = userId,
                onGetAttributesSuccess = {
                    updateAttributes(it.attributes.attributes)
                    setStatus()
                    isProgressing = false
                },
                onGetAttributesFailure = { cause ->
                    setStatus(CognitoAuthenticator.reduceFailCause(cause), true)
                    isProgressing = false
                },
                defaultFailCause = context.getString(R.string.ui_doctorScreen_defaultFetchingFailCause)
            )
        }
    }

    private fun updateAttributes(attributes: Map<String, String>) {
        doctorAttributes.clear()
        attributes.forEach { (key, value) ->
            doctorAttributes[key] = value.ifBlank { Doctor.DEFAULT_UNKNOWN_VALUE }
        }
    }

    fun onSignOutRequest() {
        showSignOutAlertDialog = true
    }
    fun onSignOutDismiss() {
        showSignOutAlertDialog = false
    }
    fun onSignOutConfirm(context: Context, onDone: () -> Unit) {
        isProgressing = true
        setStatus(SIGN_OUT_MESSAGE)
        showSignOutAlertDialog = false
        val userId = CognitoAuthenticator.getCurrentUserId(context)
        if (userId == null) {
            val showErrorJob = viewModelScope.launch {
                setStatus(SIGN_OUT_ERROR_MESSAGE, true)
                delay(MESSAGE_SHOW_TIME)
            }
            showErrorJob.invokeOnCompletion { setStatus() }
        }
        else {
            val delayJob = viewModelScope.launch {
                delay(2000L)
            }
            delayJob.invokeOnCompletion {
                CognitoAuthenticator.requestSignOut(context, userId)
                resetSession()
                onDone()
            }
        }
    }

    private fun resetSession() {
        isLaunched = false
        setStatus()
        showSignOutAlertDialog = false
        doctorAttributes.clear()
        isProgressing = false
    }

    companion object {
        const val FETCH_ATTRIBUTES_MESSAGE = "Fetching attributes"
        const val SIGN_OUT_MESSAGE = "Signing out"
        const val SIGN_OUT_ERROR_MESSAGE = "Failed to sign out. Please try again."

        const val MESSAGE_SHOW_TIME = 3000L
    }
}