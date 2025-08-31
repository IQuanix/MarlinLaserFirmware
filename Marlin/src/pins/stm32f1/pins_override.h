#pragma once

// Use FAN0 as the laser PWM (because we remapped to PB0)
#ifndef SPINDLE_LASER_PWM_PIN
  #define SPINDLE_LASER_PWM_PIN FAN0_PIN
#endif

// No separate enable / direction pins for a simple diode laser
#ifndef SPINDLE_LASER_ENA_PIN
  #define SPINDLE_LASER_ENA_PIN -1
#endif
#ifndef SPINDLE_DIR_PIN
  #define SPINDLE_DIR_PIN -1
#endif

// Most laser drivers expect active-high
#ifndef SPINDLE_LASER_ACTIVE_STATE
  #define SPINDLE_LASER_ACTIVE_STATE HIGH
#endif
