#include <pgmspace.h>

// Amazon Root CA 1 (AmazonRootCA1.pem)
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate (XXXXXXXXXX-certificate.pem.crt)
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUX4GB8WPp6Ts9yikHdr8ygY9TI2UwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIyMDMyMjA3MTU0
MFoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAN1+vDdsorMWKFQeKdCv
WoaL7gd6/ROOO0p2kW2D1WDNLoSA9Wt16O4Pn0t64pk63rE1wuEQnFzvtTlOuCDZ
YGCc80aGngQ61VNctqgAQV0Af0MzQClO6MRtgBEHepC7PQtgLVPCxI+2Km6F3Eud
DmYFFcz05/i1xrNFRQ1wHOz5tgYpJlevx/ndAhAzSEXp/ABvPw7eOAOmBXir/Qva
LyUWjyRz5tN+MiM5m5qOEOJeuSxfNGj0MZixUgdjCckaFyHjfVga+bao2PvLxHuz
QbVAI0+229hoP8MLUNHc/In7ZCDn7Xa/94XZgBQzcv1oFPtWHhOi3KfaiMNTq/vs
75kCAwEAAaNgMF4wHwYDVR0jBBgwFoAUuRF9jFHILmt6+4/eEiF40K9XjnIwHQYD
VR0OBBYEFIvtwsuAg06SWZ/XlmEJqi2je/m1MAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCSdKEawbPOYQxoyAGGXj9f+oWI
GImcf7W0atGWtawHuRGORFH/v17hchTtzX/gIQFt2H8kKp0uNIGY5BXhctuBGaDl
zLw8Jr8IpY+GGCozC9rvSsfHxYFmTkZgjH/5Cib6tTErT0hSwmDHq0I3ol/MIDh0
IqtKM5FRU+jZewFWJGT1ag5xXACa1oMzDuEmeYuXNsxTOgItTc/rvVyDUKX2/4Ba
SD4UZ8PxOXmYrQ+H8U8sP3pfqir2K1VVpNpJjYyi15gyyhHQ6gEATWWPPCp/Ya32
7sttusdCdi1IYgKTNYIBwDYoF1vtOEndFvkYn5X3T82YGpi76F2avOh7Ovm5
-----END CERTIFICATE-----
)KEY";

// Device Private Key (XXXXXXXXXX-private.pem.key)
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA3X68N2yisxYoVB4p0K9ahovuB3r9E447SnaRbYPVYM0uhID1
a3Xo7g+fS3rimTresTXC4RCcXO+1OU64INlgYJzzRoaeBDrVU1y2qABBXQB/QzNA
KU7oxG2AEQd6kLs9C2AtU8LEj7YqboXcS50OZgUVzPTn+LXGs0VFDXAc7Pm2Bikm
V6/H+d0CEDNIRen8AG8/Dt44A6YFeKv9C9ovJRaPJHPm034yIzmbmo4Q4l65LF80
aPQxmLFSB2MJyRoXIeN9WBr5tqjY+8vEe7NBtUAjT7bb2Gg/wwtQ0dz8iftkIOft
dr/3hdmAFDNy/WgU+1YeE6Lcp9qIw1Or++zvmQIDAQABAoIBAHBOqIS50q1XmM8+
FBm6L/50yRaF5/iYb7vL7uVGqVTR9Lo+4THBsX+z8CNHhcoILY5RIiUYVRBSguMx
5O7TCakzK68g5tJiOnRwWDVLG9laPS0HuYq4dhHTK9J2plDof4VbGOCVqzDrPwyX
VyIH2pskDO/FZjGXic6wWtj7dc85xMRkuZ4B3lEnurIGblBXP3RF0XtMmzRc6EPd
ml9zICT4RXKARbIhyBrXJTDdw1eI1nXLIKGRxjLKOPfFeSWjMGIcK41nm2PILqNT
9FfR31JOfoEUoLA+LLqu8dr4QxS1WRnoWwFaHxNjV6l+GWdEQI6A4xOP7wLD06Q8
XNpP1vkCgYEA97rqRDwHxYoifMoTQ3RuC4yjEAKL8+Q9tgv+UF4V2yBtlpMEGByy
twisdC4SrXZVaZ8ZsBxSj2R9G2F8pJvp7XTUGz4zM18rCBmzVUmQraDfDM/RquM/
F3pJpEeJkvRNS6Fzm+es1FGXtIDPsTXRlfmHBlYd2t+RQ6zsLQ5AV9sCgYEA5OOd
7wOb1bsKmI0J0EmLeMyhA1vHTLKFGj8SjB0zIOjwMqZBOnEn4SEPKhrIXSwAFN/M
eFpbSJaIdwmB/bxS3GVk8fOL6FYD/7n/+Cg921bRppillvsttefgAfofqElseboC
EB/WYaPiDwZFlObWZLsjSLPlt5K83waoUsO6mpsCgYEAn2FOHyBQD7NThN2tjxR1
SFDvB/nbeMo7Och1kdc2UIiIePuVAr5T7JZT/Vs3AQrE4PNPX5KZO0/3fYo22uDE
m9UyMWTPJBnyYX/HdPOjdVGur1t1FXCmwsAWaO7tf/JVWHdDHebrtp3X8HV/Kg/q
C4dCa70z8AEuQFAcktA8bUkCgYB5kGZWBi2i4zcqdGXM6PKZUt0FQp5kHsBQg0Uf
g3afOPgxfllQZ77Nc9hw/U6DJZZZf89B8INg1wpdZoBSuc2sXnGxiy84U07GaAwJ
yZ2ou8CXYaU4vei2HxO7GRPtNinVsLPdynr62qZ6YlNcVQly8G059MnBqL6FGS0W
3/tglwKBgQC1tpwYzCmpmZ3bsknThPmjuuv6c1hmiQp5gc1CEVSwCWRYCSoojvJN
SViP7AnI4+pu/EfvtewoH+5hDhusTDAFKNmrbVnQ6ID+7uJp9XAqkWMjaW9l6jwt
32mFep5UGLAqqT0TPB0z/7lxszKUwCFqKWRKfm5qzh3IeD6lgLUSuw==
-----END RSA PRIVATE KEY-----
)KEY";
