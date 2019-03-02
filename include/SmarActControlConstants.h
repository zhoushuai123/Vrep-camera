#ifndef SMARACT_CTL_CONSTANTS_H
#define SMARACT_CTL_CONSTANTS_H

/**********************/
/* GLOBAL DEFINITIONS */
/**********************/

#define SA_CTL_INFINITE                                     0xffffffff

#define SA_CTL_DISABLED                                     0x00
#define SA_CTL_ENABLED                                      0x01
#define SA_CTL_NON_INVERTED                                 0x00
#define SA_CTL_INVERTED                                     0x01
#define SA_CTL_FORWARD_DIRECTION                            0x00
#define SA_CTL_BACKWARD_DIRECTION                           0x01
#define SA_CTL_EITHER_DIRECTION                             0x02

#define SA_CTL_STRING_MAX_LENGTH                            63
#define SA_CTL_REQUEST_ID_MAX_COUNT                         240

/***************/
/* EVENT TYPES */
/***************/

#define SA_CTL_EVENT_NONE                                   0x0000

// channel events (0x0001 - 0x3fff)
#define SA_CTL_EVENT_MOVEMENT_FINISHED                      0x0001
#define SA_CTL_EVENT_SENSOR_STATE_CHANGED                   0x0002
#define SA_CTL_EVENT_REFERENCE_FOUND                        0x0003
#define SA_CTL_EVENT_FOLLOWING_ERR_LIMIT                    0x0004

// module events (0x4000 - 0x7fff)
#define SA_CTL_EVENT_SM_STATE_CHANGED                       0x4000
#define SA_CTL_EVENT_OVER_TEMPERATURE                       0x4001
#define SA_CTL_EVENT_HIGH_VOLTAGE_OVERLOAD                  0x4002
#define SA_CTL_EVENT_ADJUSTMENT_FINISHED                    0x4010
#define SA_CTL_EVENT_ADJUSTMENT_STATE_CHANGED               0x4011
#define SA_CTL_EVENT_ADJUSTMENT_UPDATE                      0x4012

// device events (0x8000 - 0xbfff)
#define SA_CTL_EVENT_STREAM_FINISHED                        0x8000
#define SA_CTL_EVENT_STREAM_READY                           0x8001
#define SA_CTL_EVENT_STREAM_TRIGGERED                       0x8002
#define SA_CTL_EVENT_CMD_GROUP_TRIGGERED                    0x8010
#define SA_CTL_EVENT_HM_STATE_CHANGED                       0x8020
#define SA_CTL_EVENT_EMERGENCY_STOP_TRIGGERED               0x8030
#define SA_CTL_EVENT_EXT_INPUT_TRIGGERED                    0x8040

// api events (0xf000 - 0xffff)
#define SA_CTL_EVENT_REQUEST_READY                          0xf000
#define SA_CTL_EVENT_CONNECTION_LOST                        0xf001

/********************/
/* EVENT PARAMETERS */
/********************/

#define SA_CTL_EVENT_PARAM_DETACHED                         0x00000000
#define SA_CTL_EVENT_PARAM_ATTACHED                         0x00000001

#define SA_CTL_EVENT_REQ_READY_TYPE_READ                    0x00
#define SA_CTL_EVENT_REQ_READY_TYPE_WRITE                   0x01

// event parameter decoding
#define SA_CTL_EVENT_PARAM_RESULT_MASK                      0x0000ffff
#define SA_CTL_EVENT_PARAM_INDEX_MASK                       0x00ff0000
#define SA_CTL_EVENT_PARAM_HANDLE_MASK                      0xff000000
#define SA_CTL_EVENT_PARAM_RESULT(param)                    (((param) & SA_CTL_EVENT_PARAM_RESULT_MASK) >> 0)
#define SA_CTL_EVENT_PARAM_INDEX(param)                     (((param) & SA_CTL_EVENT_PARAM_INDEX_MASK) >> 16)
#define SA_CTL_EVENT_PARAM_HANDLE(param)                    (((param) & SA_CTL_EVENT_PARAM_HANDLE_MASK) >> 24)

#define SA_CTL_EVENT_REQ_READY_ID_MASK                      0x00000000000000ff
#define SA_CTL_EVENT_REQ_READY_TYPE_MASK                    0x000000000000ff00
#define SA_CTL_EVENT_REQ_READY_DATA_TYPE_MASK               0x0000000000ff0000
#define SA_CTL_EVENT_REQ_READY_ARRAY_SIZE_MASK              0x00000000ff000000
#define SA_CTL_EVENT_REQ_READY_PROPERTY_KEY_MASK            0xffffffff00000000
#define SA_CTL_EVENT_REQ_READY_ID(param)                    (((param) & SA_CTL_EVENT_REQ_READY_ID_MASK) >> 0)
#define SA_CTL_EVENT_REQ_READY_TYPE(param)                  (((param) & SA_CTL_EVENT_REQ_READY_TYPE_MASK) >> 8)
#define SA_CTL_EVENT_REQ_READY_DATA_TYPE(param)             (((param) & SA_CTL_EVENT_REQ_READY_DATA_TYPE_MASK) >> 16)
#define SA_CTL_EVENT_REQ_READY_ARRAY_SIZE(param)            (((param) & SA_CTL_EVENT_REQ_READY_ARRAY_SIZE_MASK) >> 24)
#define SA_CTL_EVENT_REQ_READY_PROPERTY_KEY(param)          (((param) & SA_CTL_EVENT_REQ_READY_PROPERTY_KEY_MASK) >> 32)

 /***************/
 /* ERROR CODES */
 /***************/

#define SA_CTL_ERROR_NONE                                   0x0000
#define SA_CTL_ERROR_UNKNOWN_COMMAND                        0x0001
#define SA_CTL_ERROR_INVALID_PACKET_SIZE                    0x0002
#define SA_CTL_ERROR_TIMEOUT                                0x0004
#define SA_CTL_ERROR_INVALID_PROTOCOL                       0x0005
#define SA_CTL_ERROR_BUFFER_UNDERFLOW                       0x000c
#define SA_CTL_ERROR_BUFFER_OVERFLOW                        0x000d
#define SA_CTL_ERROR_INVALID_FRAME_SIZE                     0x000e
#define SA_CTL_ERROR_INVALID_PACKET                         0x0010
#define SA_CTL_ERROR_INVALID_KEY                            0x0012
#define SA_CTL_ERROR_INVALID_PARAMETER                      0x0013
#define SA_CTL_ERROR_INVALID_DATA_TYPE                      0x0016
#define SA_CTL_ERROR_INVALID_DATA                           0x0017
#define SA_CTL_ERROR_HANDLE_LIMIT_REACHED                   0x0018
#define SA_CTL_ERROR_ABORTED                                0x0019

#define SA_CTL_ERROR_INVALID_DEVICE_INDEX                   0x0020
#define SA_CTL_ERROR_INVALID_MODULE_INDEX                   0x0021
#define SA_CTL_ERROR_INVALID_CHANNEL_INDEX                  0x0022

#define SA_CTL_ERROR_PERMISSION_DENIED                      0x0023
#define SA_CTL_ERROR_COMMAND_NOT_GROUPABLE                  0x0024
#define SA_CTL_ERROR_MOVEMENT_LOCKED                        0x0025
#define SA_CTL_ERROR_SYNC_FAILED                            0x0026
#define SA_CTL_ERROR_INVALID_ARRAY_SIZE                     0x0027
#define SA_CTL_ERROR_OVERRANGE                              0x0028
#define SA_CTL_ERROR_INVALID_CONFIGURATION                  0x0029

#define SA_CTL_ERROR_NO_HM_PRESENT                          0x0100
#define SA_CTL_ERROR_NO_IOM_PRESENT                         0x0101
#define SA_CTL_ERROR_NO_SM_PRESENT                          0x0102
#define SA_CTL_ERROR_NO_SENSOR_PRESENT                      0x0103
#define SA_CTL_ERROR_SENSOR_DISABLED                        0x0104
#define SA_CTL_ERROR_POWER_SUPPLY_DISABLED                  0x0105
#define SA_CTL_ERROR_AMPLIFIER_DISABLED                     0x0106
#define SA_CTL_ERROR_INVALID_SENSOR_MODE                    0x0107
#define SA_CTL_ERROR_INVALID_ACTUATOR_MODE                  0x0108
#define SA_CTL_ERROR_INVALID_INPUT_TRIG_MODE                0x0109
#define SA_CTL_ERROR_INVALID_CONTROL_OPTIONS                0x010a
#define SA_CTL_ERROR_INVALID_REFERENCE_TYPE                 0x010b
#define SA_CTL_ERROR_INVALID_ADJUSTMENT_STATE               0x010c
#define SA_CTL_ERROR_INVALID_INFO_TYPE                      0x010d
#define SA_CTL_ERROR_NO_FULL_ACCESS                         0x010e
#define SA_CTL_ERROR_ADJUSTMENT_FAILED                      0x010f
#define SA_CTL_ERROR_MOVEMENT_OVERRIDDEN                    0x0110
#define SA_CTL_ERROR_NOT_CALIBRATED                         0x0111
#define SA_CTL_ERROR_NOT_REFERENCED                         0x0112
#define SA_CTL_ERROR_NOT_ADJUSTED                           0x0113
#define SA_CTL_ERROR_SENSOR_TYPE_NOT_SUPPORTED              0x0114
#define SA_CTL_ERROR_CONTROL_LOOP_INPUT_DISABLED            0x0115

#define SA_CTL_ERROR_BUSY_MOVING                            0x0150
#define SA_CTL_ERROR_BUSY_CALIBRATING                       0x0151
#define SA_CTL_ERROR_BUSY_REFERENCING                       0x0152
#define SA_CTL_ERROR_BUSY_ADJUSTING                         0x0153

#define SA_CTL_ERROR_END_STOP_REACHED                       0x0200
#define SA_CTL_ERROR_FOLLOWING_ERR_LIMIT                    0x0201
#define SA_CTL_ERROR_RANGE_LIMIT_REACHED                    0x0202

#define SA_CTL_ERROR_INVALID_STREAM_HANDLE                  0x0300
#define SA_CTL_ERROR_INVALID_STREAM_CONFIGURATION           0x0301
#define SA_CTL_ERROR_INSUFFICIENT_FRAMES                    0x0302
#define SA_CTL_ERROR_BUSY_STREAMING                         0x0303

#define SA_CTL_ERROR_HM_INVALID_SLOT_INDEX                  0x0400
#define SA_CTL_ERROR_HM_INVALID_CHANNEL_INDEX               0x0401
#define SA_CTL_ERROR_HM_INVALID_GROUP_INDEX                 0x0402
#define SA_CTL_ERROR_HM_INVALID_CH_GRP_INDEX                0x0403

#define SA_CTL_ERROR_INTERNAL_COMMUNICATION                 0x0500

#define SA_CTL_ERROR_FEATURE_NOT_SUPPORTED                  0x7ffd
#define SA_CTL_ERROR_FEATURE_NOT_IMPLEMENTED                0x7ffe

// api error codes
#define SA_CTL_ERROR_DEVICE_LIMIT_REACHED                   0xf000
#define SA_CTL_ERROR_INVALID_LOCATOR                        0xf001
#define SA_CTL_ERROR_INITIALIZATION_FAILED                  0xf002
#define SA_CTL_ERROR_NOT_INITIALIZED                        0xf003
#define SA_CTL_ERROR_COMMUNICATION_FAILED                   0xf004
#define SA_CTL_ERROR_INVALID_QUERYBUFFER_SIZE               0xf006
#define SA_CTL_ERROR_INVALID_DEVICE_HANDLE                  0xf007
#define SA_CTL_ERROR_INVALID_TRANSMIT_HANDLE                0xf008
#define SA_CTL_ERROR_UNEXPECTED_PACKET_RECEIVED             0xf00f
#define SA_CTL_ERROR_CANCELED                               0xf010
#define SA_CTL_ERROR_DRIVER_FAILED                          0xf013
#define SA_CTL_ERROR_BUFFER_LIMIT_REACHED                   0xf016
#define SA_CTL_ERROR_INVALID_PROTOCOL_VERSION               0xf017
#define SA_CTL_ERROR_DEVICE_RESET_FAILED                    0xf018
#define SA_CTL_ERROR_BUFFER_EMPTY                           0xf019
#define SA_CTL_ERROR_DEVICE_NOT_FOUND                       0xf01a
#define SA_CTL_ERROR_THREAD_LIMIT_REACHED                   0xf01b

/**************/
/* DATA TYPES */
/**************/

#define SA_CTL_DTYPE_UINT16                                 0x03
#define SA_CTL_DTYPE_INT32                                  0x06
#define SA_CTL_DTYPE_INT64                                  0x0e
#define SA_CTL_DTYPE_FLOAT32                                0x10
#define SA_CTL_DTYPE_FLOAT64                                0x11
#define SA_CTL_DTYPE_STRING                                 0x12
#define SA_CTL_DTYPE_NONE                                   0xff

/*******************/
/* BASE UNIT TYPES */
/*******************/

#define SA_CTL_UNIT_NONE                                    0x00000000
#define SA_CTL_UNIT_PERCENT                                 0x00000001
#define SA_CTL_UNIT_METER                                   0x00000002
#define SA_CTL_UNIT_DEGREE                                  0x00000003
#define SA_CTL_UNIT_SECOND                                  0x00000004
#define SA_CTL_UNIT_HERTZ                                   0x00000005

/*****************/
/* PROPERTY KEYS */
/*****************/
// device
#define SA_CTL_PKEY_NUMBER_OF_CHANNELS                      0x020F0017
#define SA_CTL_PKEY_NUMBER_OF_BUS_MODULES                   0x020F0016
#define SA_CTL_PKEY_DEVICE_STATE                            0x020F000F
#define SA_CTL_PKEY_DEVICE_SERIAL_NUMBER                    0x020F005E
#define SA_CTL_PKEY_DEVICE_NAME                             0x020F003D
#define SA_CTL_PKEY_EMERGENCY_STOP_MODE                     0x020F0088
#define SA_CTL_PKEY_NETWORK_DISCOVER_MODE                   0x020F0159
// module
#define SA_CTL_PKEY_POWER_SUPPLY_ENABLED                    0x02030010
#define SA_CTL_PKEY_MODULE_STATE                            0x0203000F
#define SA_CTL_PKEY_NUMBER_OF_BUS_MODULE_CHANNELS           0x02030017
// positioner
#define SA_CTL_PKEY_AMPLIFIER_ENABLED                       0x0302000D
#define SA_CTL_PKEY_POSITIONER_CONTROL_OPTIONS              0x0302005D
#define SA_CTL_PKEY_ACTUATOR_MODE                           0x03020019
#define SA_CTL_PKEY_CONTROL_LOOP_INPUT                      0x03020018
#define SA_CTL_PKEY_POSITIONER_TYPE                         0x0302003C
#define SA_CTL_PKEY_POSITIONER_TYPE_NAME                    0x0302003D
#define SA_CTL_PKEY_MOVE_MODE                               0x03050087
#define SA_CTL_PKEY_CHANNEL_STATE                           0x0305000F
#define SA_CTL_PKEY_POSITION                                0x0305001D
#define SA_CTL_PKEY_TARGET_POSITION                         0x0305001E
#define SA_CTL_PKEY_SCAN_POSITION                           0x0305001F
#define SA_CTL_PKEY_SCAN_VELOCITY                           0x0305002A
#define SA_CTL_PKEY_HOLD_TIME                               0x03050028
#define SA_CTL_PKEY_MOVE_VELOCITY                           0x03050029
#define SA_CTL_PKEY_MOVE_ACCELERATION                       0x0305002B
#define SA_CTL_PKEY_MAX_CL_FREQUENCY                        0x0305002F
#define SA_CTL_PKEY_DEFAULT_MAX_CL_FREQUENCY                0x03050057
#define SA_CTL_PKEY_STEP_FREQUENCY                          0x0305002E
#define SA_CTL_PKEY_STEP_AMPLITUDE                          0x03050030
#define SA_CTL_PKEY_FOLLOWING_ERROR_LIMIT                   0x03050055
#define SA_CTL_PKEY_BROADCAST_STOP_OPTIONS                  0x0305005D
#define SA_CTL_PKEY_SENSOR_POWER_MODE                       0x03080019
#define SA_CTL_PKEY_SENSOR_POWER_SAVE_DELAY                 0x03080054
#define SA_CTL_PKEY_POSITION_MEAN_SHIFT                     0x03090022
#define SA_CTL_PKEY_SAFE_DIRECTION                          0x03090027
// scale
#define SA_CTL_PKEY_LOGICAL_SCALE_OFFSET                    0x02040024
#define SA_CTL_PKEY_LOGICAL_SCALE_INVERSION                 0x02040025
#define SA_CTL_PKEY_RANGE_LIMIT_MIN                         0x02040020
#define SA_CTL_PKEY_RANGE_LIMIT_MAX                         0x02040021
// calibration
#define SA_CTL_PKEY_CALIBRATION_OPTIONS                     0x0306005D
#define SA_CTL_PKEY_SIGNAL_CORRECTION_OPTIONS               0x0306001C
// referencing
#define SA_CTL_PKEY_REFERENCING_OPTIONS                     0x0307005D
#define SA_CTL_PKEY_DIST_CODE_INVERTED                      0x0307000E
#define SA_CTL_PKEY_DISTANCE_TO_REF_MARK                    0x030700A2
// tuning and customizing
#define SA_CTL_PKEY_POS_MOVEMENT_TYPE                       0x0309003F
#define SA_CTL_PKEY_POS_IS_CUSTOM_TYPE                      0x03090041
#define SA_CTL_PKEY_POS_BASE_UNIT                           0x03090042
#define SA_CTL_PKEY_POS_BASE_RESOLUTION                     0x03090043
#define SA_CTL_PKEY_POS_P_GAIN                              0x0309004B
#define SA_CTL_PKEY_POS_I_GAIN                              0x0309004C
#define SA_CTL_PKEY_POS_D_GAIN                              0x0309004D
#define SA_CTL_PKEY_POS_PID_SHIFT                           0x0309004E
#define SA_CTL_PKEY_POS_ANTI_WINDUP                         0x0309004F
#define SA_CTL_PKEY_POS_ESD_DIST_TH                         0x03090050
#define SA_CTL_PKEY_POS_ESD_COUNTER_TH                      0x03090051
#define SA_CTL_PKEY_POS_TARGET_REACHED_TH                   0x03090052
#define SA_CTL_PKEY_POS_SAVE                                0x0309000A
#define SA_CTL_PKEY_POS_WRITE_PROTECTION                    0x0309000D
// streaming
#define SA_CTL_PKEY_STREAM_BASE_RATE                        0x040F002C
#define SA_CTL_PKEY_STREAM_EXT_SYNC_RATE                    0x040F002D
#define SA_CTL_PKEY_STREAM_OPTIONS                          0x040F005D
// diagnostic
#define SA_CTL_PKEY_CHANNEL_ERROR                           0x0502007A
#define SA_CTL_PKEY_CHANNEL_TEMPERATURE                     0x05020034
#define SA_CTL_PKEY_BUS_MODULE_TEMPERATURE                  0x05030034
// io module
#define SA_CTL_PKEY_IO_MODULE_OPTIONS                       0x0603005D
#define SA_CTL_PKEY_IO_MODULE_VOLTAGE                       0x06030031
// input trigger
#define SA_CTL_PKEY_DEV_INPUT_TRIG_MODE                     0x060D0087
#define SA_CTL_PKEY_DEV_INPUT_TRIG_CONDITION                0x060D005A
// output trigger
#define SA_CTL_PKEY_CH_OUTPUT_TRIG_MODE                     0x060E0087
#define SA_CTL_PKEY_CH_OUTPUT_TRIG_POLARITY                 0x060E005B
#define SA_CTL_PKEY_CH_OUTPUT_TRIG_PULSE_WIDTH              0x060E005C
#define SA_CTL_PKEY_CH_POS_COMP_START_THRESHOLD             0x060E0058
#define SA_CTL_PKEY_CH_POS_COMP_INCREMENT                   0x060E0059
#define SA_CTL_PKEY_CH_POS_COMP_DIRECTION                   0x060E0026
// hand control module
#define SA_CTL_PKEY_HM_STATE                                0x020C000F
#define SA_CTL_PKEY_HM_LOCK_OPTIONS                         0x020C0083
#define SA_CTL_PKEY_HM_DEFAULT_LOCK_OPTIONS                 0x020C0084
// api
#define SA_CTL_PKEY_EVENT_NOTIFICATION_OPTIONS              0xF010005D
#define SA_CTL_PKEY_AUTO_RECONNECT                          0xF01000A1

/**************/
/* STATE BITS */
/**************/

// device states
#define SA_CTL_DEV_STATE_BIT_HM_PRESENT                     0x0001
#define SA_CTL_DEV_STATE_BIT_MOVEMENT_LOCKED                0x0002
#define SA_CTL_DEV_STATE_BIT_INTERNAL_COMM_FAILURE          0x0100
#define SA_CTL_DEV_STATE_BIT_CMD_GROUP_FINISHED             0x0200
#define SA_CTL_DEV_STATE_BIT_IS_STREAMING                   0x1000

// module states
#define SA_CTL_MOD_STATE_BIT_SM_PRESENT                     0x0001
#define SA_CTL_MOD_STATE_BIT_BOOSTER_PRESENT                0x0002
#define SA_CTL_MOD_STATE_BIT_ADJUSTMENT_ACTIVE              0x0004
#define SA_CTL_MOD_STATE_BIT_IOM_PRESENT                    0x0008
#define SA_CTL_MOD_STATE_BIT_INTERNAL_COMM_FAILURE          0x0100
#define SA_CTL_MOD_STATE_BIT_HIGH_VOLTAGE_FAILURE           0x1000
#define SA_CTL_MOD_STATE_BIT_HIGH_VOLTAGE_OVERLOAD          0x2000
#define SA_CTL_MOD_STATE_BIT_OVER_TEMPERATURE               0x4000

// channel states
#define SA_CTL_CH_STATE_BIT_ACTIVELY_MOVING                 0x0001
#define SA_CTL_CH_STATE_BIT_CLOSED_LOOP_ACTIVE              0x0002
#define SA_CTL_CH_STATE_BIT_CALIBRATING                     0x0004
#define SA_CTL_CH_STATE_BIT_REFERENCING                     0x0008
#define SA_CTL_CH_STATE_BIT_MOVE_DELAYED                    0x0010
#define SA_CTL_CH_STATE_BIT_SENSOR_PRESENT                  0x0020
#define SA_CTL_CH_STATE_BIT_IS_CALIBRATED                   0x0040
#define SA_CTL_CH_STATE_BIT_IS_REFERENCED                   0x0080
#define SA_CTL_CH_STATE_BIT_END_STOP_REACHED                0x0100
#define SA_CTL_CH_STATE_BIT_RANGE_LIMIT_REACHED             0x0200
#define SA_CTL_CH_STATE_BIT_FOLLOWING_LIMIT_REACHED         0x0400
#define SA_CTL_CH_STATE_BIT_MOVEMENT_FAILED                 0x0800
#define SA_CTL_CH_STATE_BIT_IS_STREAMING                    0x1000

#define SA_CTL_CH_STATE_BIT_OVER_TEMPERATURE                0x4000
#define SA_CTL_CH_STATE_BIT_REFERENCE_MARK                  0x8000

// hand control module states
#define SA_CTL_HM_STATE_BIT_INTERNAL_COMM_FAILURE           0x0100
#define SA_CTL_HM_STATE_BIT_IS_INTERNAL                     0x0200

/***************************/
/* MOVEMENT MODES          */
/***************************/

#define SA_CTL_MOVE_MODE_CL_ABSOLUTE                        0
#define SA_CTL_MOVE_MODE_CL_RELATIVE                        1
#define SA_CTL_MOVE_MODE_SCAN_ABSOLUTE                      2
#define SA_CTL_MOVE_MODE_SCAN_RELATIVE                      3
#define SA_CTL_MOVE_MODE_STEP                               4

/***************************/
/* ACTUATOR MODES          */
/***************************/

#define SA_CTL_ACTUATOR_MODE_NORMAL                         0
#define SA_CTL_ACTUATOR_MODE_QUIET                          1
#define SA_CTL_ACTUATOR_MODE_LOW_VIBRATION                  2

/***************************/
/* CONTROL LOOP INPUT      */
/***************************/

#define SA_CTL_CONTROL_LOOP_INPUT_DISABLED                  0
#define SA_CTL_CONTROL_LOOP_INPUT_POSITION                  1
#define SA_CTL_CONTROL_LOOP_INPUT_ANALOG_IN                 2
#define SA_CTL_CONTROL_LOOP_INPUT_CALC_SYS                  3

/********************************/
/* EMERGENCY STOP TRIGGER MODES */
/********************************/

#define SA_CTL_EMERGENCY_STOP_MODE_NORMAL                   0
#define SA_CTL_EMERGENCY_STOP_MODE_RESTRICTED               1
#define SA_CTL_EMERGENCY_STOP_MODE_AUTO_RELEASE             2

/*******************************/
/* COMMAND GROUP TRIGGER MODES */
/*******************************/

#define SA_CTL_CMD_GROUP_TRIGGER_MODE_DIRECT                0
#define SA_CTL_CMD_GROUP_TRIGGER_MODE_EXTERNAL              1

/************************/
/* STREAM TRIGGER MODES */
/************************/

#define SA_CTL_STREAM_TRIGGER_MODE_DIRECT                   0
#define SA_CTL_STREAM_TRIGGER_MODE_EXTERNAL_ONCE            1
#define SA_CTL_STREAM_TRIGGER_MODE_EXTERNAL_SYNC            2

/***********************/
/* STREAM OPTIONS      */
/***********************/

#define SA_CTL_STREAM_OPT_BIT_INTERPOLATION_DIS             0x00000001

/******************************/
/* POSITIONER CONTROL OPTIONS */
/******************************/

#define SA_CTL_POS_CTRL_OPT_BIT_ACC_REL_POS_DIS             0x00000001
#define SA_CTL_POS_CTRL_OPT_BIT_NO_SLIP                     0x00000002
#define SA_CTL_POS_CTRL_OPT_BIT_NO_SLIP_WHILE_HOLDING       0x00000004
#define SA_CTL_POS_CTRL_OPT_BIT_FORCED_SLIP_DIS             0x00000008
#define SA_CTL_POS_CTRL_OPT_BIT_STOP_ON_FOLLOWING_ERR       0x00000010

/***********************/
/* CALIBRATION OPTIONS */
/***********************/

#define SA_CTL_CALIB_OPT_BIT_DIRECTION                      0x00000001
#define SA_CTL_CALIB_OPT_BIT_DIST_CODE_INV_DETECT           0x00000002
#define SA_CTL_CALIB_OPT_BIT_ASC_CALIBRATION                0x00000004
#define SA_CTL_CALIB_OPT_BIT_REF_MARK_TEST                  0x00000008

/***********************/
/* REFERENCING OPTIONS */
/***********************/

#define SA_CTL_REF_OPT_BIT_START_DIR                        0x00000001
#define SA_CTL_REF_OPT_BIT_REVERSE_DIR                      0x00000002
#define SA_CTL_REF_OPT_BIT_AUTO_ZERO                        0x00000004
#define SA_CTL_REF_OPT_BIT_ABORT_ON_ENDSTOP                 0x00000008
#define SA_CTL_REF_OPT_BIT_CONTINUE_ON_REF_FOUND            0x00000010
#define SA_CTL_REF_OPT_BIT_STOP_ON_REF_FOUND                0x00000020

/***************************/
/* SENSOR POWER MODES      */
/***************************/

#define SA_CTL_SENSOR_MODE_DISABLED                         0
#define SA_CTL_SENSOR_MODE_ENABLED                          1
#define SA_CTL_SENSOR_MODE_POWER_SAVE                       2

/***************************/
/* BROADCAST STOP OPTIONS  */
/***************************/

#define SA_CTL_STOP_OPT_BIT_END_STOP_REACHED                0x00000001
#define SA_CTL_STOP_OPT_BIT_RANGE_LIMIT_REACHED             0x00000002
#define SA_CTL_STOP_OPT_BIT_FOLLOWING_LIMIT_REACHED         0x00000004

/***************************/
/* INPUT/OUTPUT TRIGGER    */
/***************************/

// device input trigger modes
#define SA_CTL_DEV_INPUT_TRIG_MODE_DISABLED                 0
#define SA_CTL_DEV_INPUT_TRIG_MODE_EMERGENCY_STOP           1
#define SA_CTL_DEV_INPUT_TRIG_MODE_STREAM                   2
#define SA_CTL_DEV_INPUT_TRIG_MODE_CMD_GROUP                3
#define SA_CTL_DEV_INPUT_TRIG_MODE_EVENT                    4

// output trigger modes
#define SA_CTL_CH_OUTPUT_TRIG_MODE_CONSTANT                 0
#define SA_CTL_CH_OUTPUT_TRIG_MODE_POSITION_COMPARE         1
#define SA_CTL_CH_OUTPUT_TRIG_MODE_TARGET_REACHED           2
#define SA_CTL_CH_OUTPUT_TRIG_MODE_ACTIVELY_MOVING          3

// trigger conditions
#define SA_CTL_TRIGGER_CONDITION_RISING                     0
#define SA_CTL_TRIGGER_CONDITION_FALLING                    1
#define SA_CTL_TRIGGER_CONDITION_EITHER                     2

// trigger polarities
#define SA_CTL_TRIGGER_POLARITY_ACTIVE_LOW                  0
#define SA_CTL_TRIGGER_POLARITY_ACTIVE_HIGH                 1

/***********************/
/* HM LOCK OPTIONS     */
/***********************/
#define SA_CTL_HM1_LOCK_OPT_BIT_GLOBAL                      0x00000001
#define SA_CTL_HM1_LOCK_OPT_BIT_CONTROL                     0x00000002
#define SA_CTL_HM1_LOCK_OPT_BIT_CHANNEL_MENU                0x00000010
#define SA_CTL_HM1_LOCK_OPT_BIT_GROUP_MENU                  0x00000020
#define SA_CTL_HM1_LOCK_OPT_BIT_SETTINGS_MENU               0x00000040
#define SA_CTL_HM1_LOCK_OPT_BIT_LOAD_CFG_MENU               0x00000080
#define SA_CTL_HM1_LOCK_OPT_BIT_SAVE_CFG_MENU               0x00000100
#define SA_CTL_HM1_LOCK_OPT_BIT_CHANNEL_NAME                0x00001000
#define SA_CTL_HM1_LOCK_OPT_BIT_POS_TYPE                    0x00002000
#define SA_CTL_HM1_LOCK_OPT_BIT_SAFE_DIR                    0x00004000
#define SA_CTL_HM1_LOCK_OPT_BIT_CALIBRATE                   0x00008000
#define SA_CTL_HM1_LOCK_OPT_BIT_REFERENCE                   0x00010000
#define SA_CTL_HM1_LOCK_OPT_BIT_SET_POSITION                0x00020000
#define SA_CTL_HM1_LOCK_OPT_BIT_MAX_CLF                     0x00040000
#define SA_CTL_HM1_LOCK_OPT_BIT_POWER_MODE                  0x00080000
#define SA_CTL_HM1_LOCK_OPT_BIT_ACTUATOR_MODE               0x00100000
#define SA_CTL_HM1_LOCK_OPT_BIT_RANGE_LIMIT                 0x00200000
#define SA_CTL_HM1_LOCK_OPT_BIT_CONTROL_LOOP_INPUT          0x00400000

/******************************/
/* EVENT NOTIFICATION OPTIONS */
/******************************/
#define SA_CTL_EVT_OPT_BIT_REQUEST_READY_ENABLED            0x00000001

/**************************/
/* CUSTOM POSITIONER TYPE */
/**************************/

#define SA_CTL_POSITIONER_TYPE_CUSTOM0                      250
#define SA_CTL_POSITIONER_TYPE_CUSTOM1                      251
#define SA_CTL_POSITIONER_TYPE_CUSTOM2                      252
#define SA_CTL_POSITIONER_TYPE_CUSTOM3                      253

/**************************/
/* WRITE PROTECTION       */
/**************************/

#define SA_CTL_POS_WRITE_PROTECTION_KEY                     0x534D4152

/**************************/
/* MOVEMENT TYPES         */
/**************************/

#define SA_CTL_POS_MOVEMENT_TYPE_LINEAR                     0
#define SA_CTL_POS_MOVEMENT_TYPE_ROTATORY                   1
#define SA_CTL_POS_MOVEMENT_TYPE_GONIOMETER                 2
#define SA_CTL_POS_MOVEMENT_TYPE_TIP_TILT                   3

/**************************/
/* IO MODULE VOLTAGE      */
/**************************/

#define SA_CTL_IO_MODULE_VOLTAGE_3V3                        0x00000000
#define SA_CTL_IO_MODULE_VOLTAGE_5V                         0x00000001

/*********************/
/* IO MODULE OPTIONS */
/*********************/

#define SA_CTL_IO_MODULE_OPT_BIT_ENABLED                    0x00000001

/*****************************/
/* SIGNAL CORRECTION OPTIONS */
/*****************************/

#define SA_CTL_SIGNAL_CORR_OPT_BIT_DAC                      0x00000002
#define SA_CTL_SIGNAL_CORR_OPT_BIT_DPEC                     0x00000008
#define SA_CTL_SIGNAL_CORR_OPT_BIT_ASC                      0x00000010

/**************************/
/* NETWORK DISCOVER MODE  */
/**************************/
#define SA_CTL_NETWORK_DISCOVER_MODE_DISABLED               0
#define SA_CTL_NETWORK_DISCOVER_MODE_PASSIVE                1
#define SA_CTL_NETWORK_DISCOVER_MODE_ACTIVE                 2

#endif // SMARACT_CTL_CONSTANTS_H
