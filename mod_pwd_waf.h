#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "http_core.h"
#include "http_request.h"

#include "ap_config.h"
#include "apr_strings.h"
#include "apr_network_io.h"
#include <apr_file_info.h>
#include <apr_file_io.h>
#include <apr_tables.h>
#include "util_script.h"

#include "readSigConfig.c"

typedef struct {
    const char *key;
    const char *value;
} KVPair;


static int LEGAL = 1001;

static int ILLEGAL = 1002;

static char * illegalStr;

static int TRAINMODE = 2001;

static int DEFENDINGMODE = 2002;

static int MODE = 2001;

KVPair *readPostParms(request_rec *r);

int checkGETParms(request_rec *r, Signiture * getSigList, int listSize);

int checkPOSTParms(request_rec *r, Signiture * postSigList, int listSize);

int checkHEADERParms(request_rec *r, Signiture * headerSigList, int listSize);

int isLegal(const char* key, const char* value, Signiture * list, int listSize);

void showIllegalStr();
