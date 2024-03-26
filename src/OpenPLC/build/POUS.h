#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM AQUA_SYS
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,LOW_DO)
  __DECLARE_VAR(BOOL,HIGH_DO)
  __DECLARE_VAR(BOOL,AIRPUMP)
  __DECLARE_VAR(BOOL,PH)
  __DECLARE_VAR(BOOL,PHALERT)
  __DECLARE_VAR(BOOL,LOW_TEMP)
  __DECLARE_VAR(BOOL,HIGH_TEMP)
  __DECLARE_VAR(BOOL,HEATING)
  __DECLARE_VAR(BOOL,WATERPUMP)
  __DECLARE_VAR(BOOL,FORCE_WPON)
  __DECLARE_VAR(BOOL,FORCE_WPOFF)

} AQUA_SYS;

void AQUA_SYS_init__(AQUA_SYS *data__, BOOL retain);
// Code part
void AQUA_SYS_body__(AQUA_SYS *data__);
#endif //__POUS_H
