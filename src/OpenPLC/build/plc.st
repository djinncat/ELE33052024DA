TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM aqua_sys
  VAR
    low_DO : BOOL;
    high_DO : BOOL;
    airpump : BOOL;
    pH : BOOL;
    pHalert : BOOL;
    low_temp : BOOL;
    high_temp : BOOL;
    heating : BOOL;
    waterpump : BOOL;
    wp_on : BOOL;
    wp_off : BOOL;
    wplatched : BOOL;
  END_VAR

  airpump := NOT(high_DO) AND (airpump OR low_DO);
  pHalert := pH;
  heating := low_temp;
  waterpump := NOT(low_temp) AND (high_temp OR wplatched);
  wplatched := NOT(wp_off) AND (wp_on OR wplatched);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : aqua_sys;
  END_RESOURCE
END_CONFIGURATION
