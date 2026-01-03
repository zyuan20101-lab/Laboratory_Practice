#include "init.h"

// ==================== GPIO 初始化函数 ====================

// GPIO_Ini_1：初始化 GPIOB 的 LED 引脚（PB0, PB1, PB7, PB8, PB14, PB15）
void GPIO_Ini_1(void)
{
    // 使能 GPIOB 和 GPIOC 的时钟
    SET_BIT(RCC_GPIO_EN, RCC_GPIOB_EN | RCC_GPIOC_EN);

    // ==================== 配置 LED1 (PB0) - 绿色LED1 ====================
    // 设置 PB0 为输出模式
    GPIOB_MODER &= ~(0x03 << (0 * 2)); // 清除 MODER0[1:0]
    GPIOB_MODER |= GPIOB_MODE_PIN0_OUT;

    // 设置 PB0 为推挽输出
    GPIOB_OTYPER &= ~(0x01 << 0); // OT0 = 0

    // 设置 PB0 的速度为中速
    GPIOB_OSPEEDR &= ~(0x03 << (0 * 2)); // 清除 OSPEEDR0[1:0]
    GPIOB_OSPEEDR |= GPIOB_OSPEED_PIN0_MID;

    // 设置 PB0 为无上下拉
    GPIOB_PUPDR &= ~(0x03 << (0 * 2)); // 清除 PUPDR0[1:0]
    GPIOB_PUPDR |= GPIOB_PUPDR_PIN0_NOPUPD;

    // 初始化 LED1 为关闭
    GPIOB_BSRR = GPIOB_BSRR_PIN0_RESET;

    // ==================== 配置 LED2 (PB1) - 绿色LED2 ====================
    // 设置 PB1 为输出模式
    GPIOB_MODER &= ~(0x03 << (1 * 2)); // 清除 MODER1[1:0]
    GPIOB_MODER |= GPIOB_MODE_PIN1_OUT;

    // 设置 PB1 为推挽输出
    GPIOB_OTYPER &= ~(0x01 << 1); // OT1 = 0

    // 设置 PB1 的速度为中速
    GPIOB_OSPEEDR &= ~(0x03 << (1 * 2)); // 清除 OSPEEDR1[1:0]
    GPIOB_OSPEEDR |= GPIOB_OSPEED_PIN1_MID;

    // 设置 PB1 为无上下拉
    GPIOB_PUPDR &= ~(0x03 << (1 * 2)); // 清除 PUPDR1[1:0]
    GPIOB_PUPDR |= GPIOB_PUPDR_PIN1_NOPUPD;

    // 初始化 LED2 为关闭
    GPIOB_BSRR = GPIOB_BSRR_PIN1_RESET;

    // ==================== 配置 LED3 (PB7) - 蓝色LED1 ====================
    // 设置 PB7 为输出模式
    GPIOB_MODER &= ~(0x03 << (7 * 2)); // 清除 MODER7[1:0]
    GPIOB_MODER |= GPIOB_MODE_PIN7_OUT;

    // 设置 PB7 为推挽输出
    GPIOB_OTYPER &= ~(0x01 << 7); // OT7 = 0

    // 设置 PB7 的速度为中速
    GPIOB_OSPEEDR &= ~(0x03 << (7 * 2)); // 清除 OSPEEDR7[1:0]
    GPIOB_OSPEEDR |= GPIOB_OSPEED_PIN7_MID;

    // 设置 PB7 为无上下拉
    GPIOB_PUPDR &= ~(0x03 << (7 * 2)); // 清除 PUPDR7[1:0]
    GPIOB_PUPDR |= GPIOB_PUPDR_PIN7_NOPUPD;

    // 初始化 LED3 为关闭
    GPIOB_BSRR = GPIOB_BSRR_PIN7_RESET;

    // ==================== 配置 LED4 (PB8) - 蓝色LED2 ====================
    // 设置 PB8 为输出模式
    GPIOB_MODER &= ~(0x03 << (8 * 2)); // 清除 MODER8[1:0]
    GPIOB_MODER |= GPIOB_MODE_PIN8_OUT;

    // 设置 PB8 为推挽输出
    GPIOB_OTYPER &= ~(0x01 << 8); // OT8 = 0

    // 设置 PB8 的速度为中速
    GPIOB_OSPEEDR &= ~(0x03 << (8 * 2)); // 清除 OSPEEDR8[1:0]
    GPIOB_OSPEEDR |= GPIOB_OSPEED_PIN8_MID;

    // 设置 PB8 为无上下拉
    GPIOB_PUPDR &= ~(0x03 << (8 * 2)); // 清除 PUPDR8[1:0]
    GPIOB_PUPDR |= GPIOB_PUPDR_PIN8_NOPUPD;

    // 初始化 LED4 为关闭
    GPIOB_BSRR = GPIOB_BSRR_PIN8_RESET;

    // ==================== 配置 LED5 (PB14) - 红色LED1 ====================
    // 设置 PB14 为输出模式
    GPIOB_MODER &= ~(0x03 << (14 * 2)); // 清除 MODER14[1:0]
    GPIOB_MODER |= GPIOB_MODE_PIN14_OUT;

    // 设置 PB14 为推挽输出
    GPIOB_OTYPER &= ~(0x01 << 14); // OT14 = 0

    // 设置 PB14 的速度为中速
    GPIOB_OSPEEDR &= ~(0x03 << (14 * 2)); // 清除 OSPEEDR14[1:0]
    GPIOB_OSPEEDR |= GPIOB_OSPEED_PIN14_MID;

    // 设置 PB14 为无上下拉
    GPIOB_PUPDR &= ~(0x03 << (14 * 2)); // 清除 PUPDR14[1:0]
    GPIOB_PUPDR |= GPIOB_PUPDR_PIN14_NOPUPD;

    // 初始化 LED5 为关闭
    GPIOB_BSRR = GPIOB_BSRR_PIN14_RESET;

    // ==================== 配置 LED6 (PB15) - 红色LED2 ====================
    // 设置 PB15 为输出模式
    GPIOB_MODER &= ~(0x03 << (15 * 2)); // 清除 MODER15[1:0]
    GPIOB_MODER |= GPIOB_MODE_PIN15_OUT;

    // 设置 PB15 为推挽输出
    GPIOB_OTYPER &= ~(0x01 << 15); // OT15 = 0

    // 设置 PB15 的速度为中速
    GPIOB_OSPEEDR &= ~(0x03 << (15 * 2)); // 清除 OSPEEDR15[1:0]
    GPIOB_OSPEEDR |= GPIOB_OSPEED_PIN15_MID;

    // 设置 PB15 为无上下拉
    GPIOB_PUPDR &= ~(0x03 << (15 * 2)); // 清除 PUPDR15[1:0]
    GPIOB_PUPDR |= GPIOB_PUPDR_PIN15_NOPUPD;

    // 初始化 LED6 为关闭
    GPIOB_BSRR = GPIOB_BSRR_PIN15_RESET;
}

// GPIO_Ini_2：初始化 GPIOC 的按钮引脚（PC6, PC7, PC8, PC9）
void GPIO_Ini_2(void)
{
    // ==================== 配置 按钮1 (PC9), 按钮2 (PC6), 按钮3 (PC7), 按钮4 (PC8) 为输入模式 ====================
    // 设置 PC9 为输入模式
    GPIOC_MODER &= ~(0x03 << (9 * 2)); // 清除 MODER9[1:0]

    // 设置 PC6 为输入模式
    GPIOC_MODER &= ~(0x03 << (6 * 2)); // 清除 MODER6[1:0]

    // 设置 PC7 为输入模式
    GPIOC_MODER &= ~(0x03 << (7 * 2)); // 清除 MODER7[1:0]

    // 设置 PC8 为输入模式
    GPIOC_MODER &= ~(0x03 << (8 * 2)); // 清除 MODER8[1:0]

    // ==================== 配置 上下拉电阻 ====================
    // 设置 PC9 为无上下拉
    GPIOC_PUPDR &= ~(0x03 << (9 * 2));
    GPIOC_PUPDR |= (0x00 << (9 * 2)); // 无上下拉

    // 设置 PC6 为无上下拉
    GPIOC_PUPDR &= ~(0x03 << (6 * 2));
    GPIOC_PUPDR |= (0x00 << (6 * 2)); // 无上下拉

    // 设置 PC7 为无上下拉
    GPIOC_PUPDR &= ~(0x03 << (7 * 2));
    GPIOC_PUPDR |= (0x00 << (7 * 2)); // 无上下拉

    // 设置 PC8 为无上下拉
    GPIOC_PUPDR &= ~(0x03 << (8 * 2));
    GPIOC_PUPDR |= (0x00 << (8 * 2)); // 无上下拉
}
