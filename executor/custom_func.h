
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define CUSTOM_FUNC_NR_OFFSET 1000

#define GRANTPT (1000-CUSTOM_FUNC_NR_OFFSET)
#define PTSNAME_R (1001-CUSTOM_FUNC_NR_OFFSET)
#define CFMAKERAW (1002-CUSTOM_FUNC_NR_OFFSET)

typedef intptr_t(* custom_func_t)(intptr_t, intptr_t, intptr_t, intptr_t, intptr_t, intptr_t, intptr_t, intptr_t, intptr_t);

const custom_func_t custom_funcs[] = {
	[GRANTPT] = (custom_func_t)grantpt,
	[PTSNAME_R] = (custom_func_t)ptsname_r,
	[CFMAKERAW] = (custom_func_t)cfmakeraw,
};

static intptr_t execute_custom_func(const call_t* c, intptr_t a[kMaxArgs])
{
	return custom_funcs[c->sys_nr - CUSTOM_FUNC_NR_OFFSET](a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
}