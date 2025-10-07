# MarlinLaserFirmware
This Version is ready to use with a Ender 5 Pro or Ender 5 with a silent board upgrade.
Board Firmware should be V4..
(Should work with any V4.X.X version now, but didn't test it)

## Following parameters got changed/added:
(search fo names to find location)

### In Marlin\Configuration.h:
**Make sure this is commented out!**\
//#define ENDER5_USE_BLTOUCH


**Starting at ~line 3670:**\
#define LASER_FEATURE
#define SPINDLE_LASER_USE_PWM
#undef  SPEED_POWER_INTERCEPT
#undef  SPEED_POWER_MIN
#undef  SPEED_POWER_MAX
#define SPEED_POWER_INTERCEPT 0
#define SPEED_POWER_MIN       0
#define SPEED_POWER_MAX       100

#define SPINDLE_LASER_FREQUENCY     5000

**Commented out for option of framing**
**(set time if you need the safety feature)**
//#define LASER_SAFETY_TIMEOUT_MS     60000

**Sync power with steps**
#define LASER_POWER_SYNC
#define LASER_POWER_TRAP

### In Marlin\src\pins\stm32f1\pins_Creality_V4.h:

**Make sure this pin is PB0 (BL_Touch_pwm_pin)**
#define SERVO0_PIN                      PB0

**Remove this in case the printer tries to use the fan_pin for pwm**
#ifndef FAN0_PIN
  #define FAN0_PIN                          PA0   // FAN

**Add the following to the end of the code to make sure everything is set globaly**

// laser on BL_T “IN” pin
// PB0 is the BLTouch servo signal (3.3 V, PWM).

#ifdef SPINDLE_LASER_PWM_PIN
  #undef SPINDLE_LASER_PWM_PIN
#endif
#define SPINDLE_LASER_PWM_PIN PB0   // <- Laser PWM out on BL_T "IN"

// turn off enableing pin (could be used as second safety)
#ifdef SPINDLE_LASER_ENA_PIN
  #undef SPINDLE_LASER_ENA_PIN
#endif
#define SPINDLE_LASER_ENA_PIN -1    // No separate enable

#ifdef SPINDLE_DIR_PIN
  #undef SPINDLE_DIR_PIN
#endif
#define SPINDLE_DIR_PIN -1          // Not used for lasers, better turn off

#ifndef SPINDLE_LASER_ACTIVE_STATE
  #define SPINDLE_LASER_ACTIVE_STATE HIGH
#endif
