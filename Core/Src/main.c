#include "init.h"
#include <stdint.h>

// ==================== 全局变量 ====================
uint8_t led_states[3] = {0}; // 记录每个 LED 的当前状态 (0=关闭, 1=打开)
                                // led_states[0] 对应 LED1 (PB0)
                                // led_states[1] 对应 LED2 (PB7)
                                // led_states[2] 对应 LED3 (PB14)
uint8_t button1_mode = 0;      // 按钮1的功能模式 (0=开灯, 1=关灯)
uint8_t button1_pressed = 0;   // 按钮1是否被按下
uint8_t button2_pressed = 0;   // 按钮2是否被按下

// ==================== 函数原型 ====================
void update_leds(void);
void delay(volatile uint32_t s);

int main(void)
{
    // 初始化 GPIO 引脚
    GPIO_Ini_1(); // 初始化 LED 引脚 (PB0, PB7, PB14)
    GPIO_Ini_2(); // 初始化按钮引脚 (PC6, PC13)

    while (1)
    {
        // 读取按钮1 (PC13) 和按钮2 (PC6) 的状态
        uint32_t button1_state = GPIOC_IDR & GPIOC_IDR_PIN13;
        uint32_t button2_state = GPIOC_IDR & GPIOC_IDR_PIN6;

        // ==================== 按钮1 逻辑 ====================
        if (!button1_state) // 按钮1按下时，IDR对应位为低电平
        {
            if (!button1_pressed)
            {
                button1_pressed = 1;

                if (button1_mode == 0) // 开灯模式
                {
                    // 按顺序开灯：PB0 -> PB7 -> PB14
                    for (int i = 0; i < 3; i++)
                    {
                        if (led_states[i] == 0)
                        {
                            led_states[i] = 1; // 打开对应 LED
                            break; // 只打开一个 LED
                        }
                    }
                }
                else // 关灯模式
                {
                    // 按顺序关灯：PB14 -> PB7 -> PB0
                    for (int i = 2; i >= 0; i--)
                    {
                        if (led_states[i] == 1)
                        {
                            led_states[i] = 0; // 关闭对应 LED
                            break; // 只关闭一个 LED
                        }
                    }
                }

                update_leds(); // 更新 LED 状态
            }
        }
        else
        {
            button1_pressed = 0; // 按钮1释放
        }

        // ==================== 按钮2 逻辑 ====================
        if (!button2_state) // 按钮2按下时，IDR对应位为低电平
        {
            if (!button2_pressed)
            {
                button2_pressed = 1;
                button1_mode = !button1_mode; // 切换按钮1的功能模式
            }
        }
        else
        {
            button2_pressed = 0; // 按钮2释放
        }

        // ==================== 防抖延时 ====================
        delay(100000); // 简单延时用于按键防抖
    }
}

// ==================== 更新 LED 状态函数 ====================
void update_leds(void)
{
    // 关闭所有 LED
    GPIOB_BSRR = GPIOB_BSRR_PIN0_RESET | GPIOB_BSRR_PIN7_RESET | GPIOB_BSRR_PIN14_RESET;

    // 根据 led_states 数组打开相应的 LED
    if (led_states[0])
        GPIOB_BSRR = GPIOB_BSRR_PIN0_SET;
    if (led_states[1])
        GPIOB_BSRR = GPIOB_BSRR_PIN7_SET;
    if (led_states[2])
        GPIOB_BSRR = GPIOB_BSRR_PIN14_SET;
}

// ==================== 延时函数 ====================
void delay(volatile uint32_t s)
{
    while (s--)
        ;
}
