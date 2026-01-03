#include "init.h"
#include <stdint.h>

// ==================== 全局变量 ====================
uint8_t led_states[6] = {0}; // 记录每个 LED 的当前状态 (0=关闭, 1=打开)
// LED 映射: [0]=绿1, [1]=绿2, [2]=蓝1, [3]=蓝2, [4]=红1, [5]=红2

uint8_t button_pressed[4] = {0};      // 记录每个按钮的按下状态
uint8_t button_debounce[4] = {0};     // 按钮防抖计数器
uint8_t mode_count = 0;               // 按键4的按下次数计数
uint8_t color_mapping[3] = {0, 1, 2}; // 颜色映射: [0]=按键1颜色, [1]=按键2颜色, [2]=按键3颜色
// 颜色定义: 0=绿色, 1=蓝色, 2=红色

// ==================== 函数原型 ====================
void update_leds(void);
void delay_ms(uint32_t ms);
void update_color_mapping(void);
uint8_t read_button(uint32_t button_mask, uint8_t button_index);

int main(void)
{
    // 初始化 GPIO
    GPIO_Ini_1(); // 初始化 LED 引脚
    GPIO_Ini_2(); // 初始化按钮引脚

    while (1)
    {
        // ==================== 按钮4 逻辑 (模式切换) ====================
        if (read_button(GPIOC_IDR_PIN8, 3)) // 读取按钮4状态
        {
            if (!button_pressed[3])
            {
                button_pressed[3] = 1;
                mode_count = (mode_count + 1) % 3; // 循环计数 0,1,2
                update_color_mapping();
            }
        }
        else
        {
            button_pressed[3] = 0;
        }

        // ==================== 按钮1 逻辑 (按住点亮) ====================
        if (read_button(GPIOC_IDR_PIN9, 0)) // 读取按钮1状态
        {
            if (!button_pressed[0])
            {
                button_pressed[0] = 1;

                // 根据当前颜色映射点亮对应的两个LED
                uint8_t color = color_mapping[0];
                if (color == 0)
                {                      // 绿色
                    led_states[0] = 1; // 绿1
                    led_states[1] = 1; // 绿2
                }
                else if (color == 1)
                {                      // 蓝色
                    led_states[2] = 1; // 蓝1
                    led_states[3] = 1; // 蓝2
                }
                else if (color == 2)
                {                      // 红色
                    led_states[4] = 1; // 红1
                    led_states[5] = 1; // 红2
                }
                update_leds();
            }
        }
        else
        {
            if (button_pressed[0])
            {
                button_pressed[0] = 0;

                // 松开时熄灭对应的两个LED
                uint8_t color = color_mapping[0];
                if (color == 0)
                {                      // 绿色
                    led_states[0] = 0; // 绿1
                    led_states[1] = 0; // 绿2
                }
                else if (color == 1)
                {                      // 蓝色
                    led_states[2] = 0; // 蓝1
                    led_states[3] = 0; // 蓝2
                }
                else if (color == 2)
                {                      // 红色
                    led_states[4] = 0; // 红1
                    led_states[5] = 0; // 红2
                }
                update_leds();
            }
        }

        // ==================== 按钮2 逻辑 (按住点亮) ====================
        if (read_button(GPIOC_IDR_PIN6, 1)) // 读取按钮2状态
        {
            if (!button_pressed[1])
            {
                button_pressed[1] = 1;

                // 根据当前颜色映射点亮对应的两个LED
                uint8_t color = color_mapping[1];
                if (color == 0)
                {                      // 绿色
                    led_states[0] = 1; // 绿1
                    led_states[1] = 1; // 绿2
                }
                else if (color == 1)
                {                      // 蓝色
                    led_states[2] = 1; // 蓝1
                    led_states[3] = 1; // 蓝2
                }
                else if (color == 2)
                {                      // 红色
                    led_states[4] = 1; // 红1
                    led_states[5] = 1; // 红2
                }
                update_leds();
            }
        }
        else
        {
            if (button_pressed[1])
            {
                button_pressed[1] = 0;

                // 松开时熄灭对应的两个LED
                uint8_t color = color_mapping[1];
                if (color == 0)
                {                      // 绿色
                    led_states[0] = 0; // 绿1
                    led_states[1] = 0; // 绿2
                }
                else if (color == 1)
                {                      // 蓝色
                    led_states[2] = 0; // 蓝1
                    led_states[3] = 0; // 蓝2
                }
                else if (color == 2)
                {                      // 红色
                    led_states[4] = 0; // 红1
                    led_states[5] = 0; // 红2
                }
                update_leds();
            }
        }

        // ==================== 按钮3 逻辑 (按住点亮) ====================
        if (read_button(GPIOC_IDR_PIN7, 2)) // 读取按钮3状态
        {
            if (!button_pressed[2])
            {
                button_pressed[2] = 1;

                // 根据当前颜色映射点亮对应的两个LED
                uint8_t color = color_mapping[2];
                if (color == 0)
                {                      // 绿色
                    led_states[0] = 1; // 绿1
                    led_states[1] = 1; // 绿2
                }
                else if (color == 1)
                {                      // 蓝色
                    led_states[2] = 1; // 蓝1
                    led_states[3] = 1; // 蓝2
                }
                else if (color == 2)
                {                      // 红色
                    led_states[4] = 1; // 红1
                    led_states[5] = 1; // 红2
                }
                update_leds();
            }
        }
        else
        {
            if (button_pressed[2])
            {
                button_pressed[2] = 0;

                // 松开时熄灭对应的两个LED
                uint8_t color = color_mapping[2];
                if (color == 0)
                {                      // 绿色
                    led_states[0] = 0; // 绿1
                    led_states[1] = 0; // 绿2
                }
                else if (color == 1)
                {                      // 蓝色
                    led_states[2] = 0; // 蓝1
                    led_states[3] = 0; // 蓝2
                }
                else if (color == 2)
                {                      // 红色
                    led_states[4] = 0; // 红1
                    led_states[5] = 0; // 红2
                }
                update_leds();
            }
        }

        // ==================== 短延时防抖 ====================
        delay_ms(10); // 10ms延时，用于防抖和降低CPU使用率
    }
}

// ==================== 读取按钮状态函数（带防抖） ====================
uint8_t read_button(uint32_t button_mask, uint8_t button_index)
{
    uint32_t button_state = GPIOC_IDR & button_mask;

    if (!button_state) // 低电平有效（按下）
    {
        if (button_debounce[button_index] < 5)
        {
            button_debounce[button_index]++;
        }
    }
    else // 高电平（释放）
    {
        if (button_debounce[button_index] > 0)
        {
            button_debounce[button_index]--;
        }
    }

    // 防抖：连续5次检测到按下才认为是真按下
    return (button_debounce[button_index] >= 5);
}

// ==================== 更新颜色映射函数 ====================
void update_color_mapping(void)
{
    if (mode_count == 0)
    {
        // 初始模式：按键1=绿, 按键2=蓝, 按键3=红
        color_mapping[0] = 0; // 绿色
        color_mapping[1] = 1; // 蓝色
        color_mapping[2] = 2; // 红色
    }
    else if (mode_count == 1)
    {
        // 第一次按下按键4：颜色下移一位
        color_mapping[0] = 2; // 红色
        color_mapping[1] = 0; // 绿色
        color_mapping[2] = 1; // 蓝色
    }
    else if (mode_count == 2)
    {
        // 第二次按下按键4：颜色再下移一位
        color_mapping[0] = 1; // 蓝色
        color_mapping[1] = 2; // 红色
        color_mapping[2] = 0; // 绿色
    }
    // 第三次按下按键4时，mode_count=0，回到初始模式
}

// ==================== 更新 LED 状态函数 ====================
void update_leds(void)
{
    // 根据 led_states 数组控制所有LED
    // 绿1 (PB0)
    if (led_states[0])
        GPIOB_BSRR = GPIOB_BSRR_PIN0_SET;
    else
        GPIOB_BSRR = GPIOB_BSRR_PIN0_RESET;

    // 绿2 (PB1)
    if (led_states[1])
        GPIOB_BSRR = GPIOB_BSRR_PIN1_SET;
    else
        GPIOB_BSRR = GPIOB_BSRR_PIN1_RESET;

    // 蓝1 (PB7)
    if (led_states[2])
        GPIOB_BSRR = GPIOB_BSRR_PIN7_SET;
    else
        GPIOB_BSRR = GPIOB_BSRR_PIN7_RESET;

    // 蓝2 (PB8)
    if (led_states[3])
        GPIOB_BSRR = GPIOB_BSRR_PIN8_SET;
    else
        GPIOB_BSRR = GPIOB_BSRR_PIN8_RESET;

    // 红1 (PB14)
    if (led_states[4])
        GPIOB_BSRR = GPIOB_BSRR_PIN14_SET;
    else
        GPIOB_BSRR = GPIOB_BSRR_PIN14_RESET;

    // 红2 (PB15)
    if (led_states[5])
        GPIOB_BSRR = GPIOB_BSRR_PIN15_SET;
    else
        GPIOB_BSRR = GPIOB_BSRR_PIN15_RESET;
}

// ==================== 毫秒延时函数 ====================
void delay_ms(uint32_t ms)
{
    // 简单的延时函数，实际时间取决于CPU频率
    for (uint32_t i = 0; i < ms; i++)
    {
        for (volatile uint32_t j = 0; j < 10000; j++)
            ;
    }
}
