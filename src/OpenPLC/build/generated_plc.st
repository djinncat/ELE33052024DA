PROGRAM aqua_sys
  VAR
    low_DO AT %QX0.0 : BOOL;
    high_DO AT %QX0.1 : BOOL;
    airpump AT %QX0.2 : BOOL;
    pH AT %QX0.3 : BOOL;
    pHalert AT %QX0.4 : BOOL;
    low_temp AT %QX0.5 : BOOL;
    high_temp AT %QX0.6 : BOOL;
    heating AT %QX0.7 : BOOL;
    waterpump AT %QX1.0 : BOOL;
    force_wpon AT %QX1.1 : BOOL;
    force_wpoff AT %QX1.2 : BOOL;
  END_VAR

  airpump := NOT(high_DO) AND (airpump OR low_DO);
  pHalert := pH;
  heating := low_temp;
  waterpump := (force_wpon OR high_temp) AND NOT(force_wpoff);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : aqua_sys;
  END_RESOURCE
END_CONFIGURATION
