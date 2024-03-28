void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void AQUA_SYS_init__(AQUA_SYS *data__, BOOL retain) {
  __INIT_VAR(data__->LOW_DO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HIGH_DO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AIRPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PHALERT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOW_TEMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HIGH_TEMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HEATING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WATERPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WP_ON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WP_OFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WPLATCHED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void AQUA_SYS_body__(AQUA_SYS *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,AIRPUMP,,(!(__GET_VAR(data__->HIGH_DO,)) && (__GET_VAR(data__->AIRPUMP,) || __GET_VAR(data__->LOW_DO,))));
  __SET_VAR(data__->,PHALERT,,__GET_VAR(data__->PH,));
  __SET_VAR(data__->,HEATING,,__GET_VAR(data__->LOW_TEMP,));
  __SET_VAR(data__->,WATERPUMP,,(!(__GET_VAR(data__->LOW_TEMP,)) && (__GET_VAR(data__->HIGH_TEMP,) || __GET_VAR(data__->WPLATCHED,))));
  __SET_VAR(data__->,WPLATCHED,,(!(__GET_VAR(data__->WP_OFF,)) && (__GET_VAR(data__->WP_ON,) || __GET_VAR(data__->WPLATCHED,))));

  goto __end;

__end:
  return;
} // AQUA_SYS_body__() 





