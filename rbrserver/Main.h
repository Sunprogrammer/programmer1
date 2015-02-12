#pragma once
#include "CLog.h"

#define SAFE_DELETE(d) if(d) { delete(d); (d)=NULL; }

#define PROJECT_NAME "RBR "
#define PROJECT_STRING "Server RBR"
#define PROJECT_WEBSITE "http://maparbr.com.br/"
#define VERSION_STRING "Desenvolvimento ("__DATE__", "__TIME__")"
#define SERVER_VERSION_STRING PROJECT_NAME" "VERSION_STRING
