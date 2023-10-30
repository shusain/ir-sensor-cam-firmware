
// Board Pin Definitions
#define PWDN_GPIO_NUM       -1
#define RESET_GPIO_NUM      -1

#define XCLK_GPIO_NUM       32
#define SIOD_GPIO_NUM       13
#define SIOC_GPIO_NUM       12

#define Y9_GPIO_NUM         GPIO_NUM_39
#define Y8_GPIO_NUM         GPIO_NUM_36
#define Y7_GPIO_NUM         GPIO_NUM_23
#define Y6_GPIO_NUM         GPIO_NUM_18
#define Y5_GPIO_NUM         GPIO_NUM_15
#define Y4_GPIO_NUM         GPIO_NUM_4
#define Y3_GPIO_NUM         GPIO_NUM_14
#define Y2_GPIO_NUM         GPIO_NUM_5

#define VSYNC_GPIO_NUM      GPIO_NUM_27
#define HREF_GPIO_NUM       GPIO_NUM_25
#define PCLK_GPIO_NUM       GPIO_NUM_19

#define I2C_SDA             GPIO_NUM_21
#define I2C_SCL             GPIO_NUM_22

#define BUTTON_1            GPIO_NUM_34

#define SSD130_MODLE_TYPE   0   // 0 : GEOMETRY_128_64  // 1: GEOMETRY_128_32

#define AS312_PIN           GPIO_NUM_33

#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<I2C_SDA) | (1ULL<<I2C_SCL)) 
#define GPIO_INPUT_PIN_SEL ((1ULL<<AS312_PIN))