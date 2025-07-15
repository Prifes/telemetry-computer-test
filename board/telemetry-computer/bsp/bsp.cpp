#include "bsp.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "gpio.h"

extern "C" void SystemClock_Config(void);

namespace board {
void Initialize() {
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();  // Initialize GPIO pins
}
void ToggleLed() {
    // Assuming GPIO pin for LED is configured, toggle the LED state
    HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);  // Example: Toggle pin 0 on port B
    HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);  // Example: Toggle pin 0 on port B
    HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);  // Example: Toggle pin 0 on port B
}
void Delay(uint32_t ms) {
    HAL_Delay(ms);  // Use HAL library to create a delay
}
}