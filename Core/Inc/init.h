#ifndef INIT_H
#define INIT_H

#include <stdint.h>

#include "..\..\CMSIS\Devices\Inc\stm32f4xx.h"
#include "..\..\CMSIS\Devices\Inc\stm32f429xx.h"
#include "..\..\CMSIS\Devices\Inc\system_stm32f4xx.h"

// 使能时钟寄存器地址
#define RCC_GPIO_EN (*(uint32_t *)(0x40023800UL + 0x30UL))

// 使能 GPIOB 和 GPIOC 的时钟位掩码
#define RCC_GPIOB_EN 0x02UL
#define RCC_GPIOC_EN 0x04UL

// GPIOB 寄存器定义
#define GPIOB_MODER (*(uint32_t *)(0x40020400UL + 0x00UL))
#define GPIOB_OTYPER (*(uint32_t *)(0x40020400UL + 0x04UL))
#define GPIOB_OSPEEDR (*(uint32_t *)(0x40020400UL + 0x08UL))
#define GPIOB_PUPDR (*(uint32_t *)(0x40020400UL + 0x0CUL))
#define GPIOB_BSRR (*(uint32_t *)(0x40020400UL + 0x18UL))

// GPIOC 寄存器定义
#define GPIOC_MODER (*(uint32_t *)(0x40020800UL + 0x00UL))
#define GPIOC_PUPDR (*(uint32_t *)(0x40020800UL + 0x0CUL))
#define GPIOC_IDR (*(uint32_t *)(0x40020800UL + 0x10UL))

// 按钮引脚位掩码
#define GPIOC_IDR_PIN6 0x000040UL // PC6
#define GPIOC_IDR_PIN7 0x000080UL // PC7
#define GPIOC_IDR_PIN8 0x000100UL // PC8
#define GPIOC_IDR_PIN9 0x000200UL // PC9

// LED1 (PB0) 配置
#define GPIOB_MODE_PIN0_OUT (0x01 << (0 * 2))     // MODER0[1:0] = 01 (输出)
#define GPIOB_OTYPE_PIN0_PP (0x00 << 0)           // OT0 = 0 (推挽)
#define GPIOB_OSPEED_PIN0_MID (0x01 << (0 * 2))   // OSPEEDR0[1:0] = 01 (中速)
#define GPIOB_PUPDR_PIN0_NOPUPD (0x00 << (0 * 2)) // PUPDR0[1:0] = 00 (无上下拉)
#define GPIOB_BSRR_PIN0_SET (1 << 0)              // BSRR 设置 PB0
#define GPIOB_BSRR_PIN0_RESET (1 << (16 + 0))     // BSRR 重置 PB0

// LED2 (PB1) 配置 - 绿色LED2
#define GPIOB_MODE_PIN1_OUT (0x01 << (1 * 2))     // MODER1[1:0] = 01 (输出)
#define GPIOB_OTYPE_PIN1_PP (0x00 << 1)           // OT1 = 0 (推挽)
#define GPIOB_OSPEED_PIN1_MID (0x01 << (1 * 2))   // OSPEEDR1[1:0] = 01 (中速)
#define GPIOB_PUPDR_PIN1_NOPUPD (0x00 << (1 * 2)) // PUPDR1[1:0] = 00 (无上下拉)
#define GPIOB_BSRR_PIN1_SET (1 << 1)              // BSRR 设置 PB1
#define GPIOB_BSRR_PIN1_RESET (1 << (16 + 1))     // BSRR 重置 PB1

// LED3 (PB7) 配置 - 蓝色LED1
#define GPIOB_MODE_PIN7_OUT (0x01 << (7 * 2))     // MODER7[1:0] = 01 (输出)
#define GPIOB_OTYPE_PIN7_PP (0x00 << 7)           // OT7 = 0 (推挽)
#define GPIOB_OSPEED_PIN7_MID (0x01 << (7 * 2))   // OSPEEDR7[1:0] = 01 (中速)
#define GPIOB_PUPDR_PIN7_NOPUPD (0x00 << (7 * 2)) // PUPDR7[1:0] = 00 (无上下拉)
#define GPIOB_BSRR_PIN7_SET (1 << 7)              // BSRR 设置 PB7
#define GPIOB_BSRR_PIN7_RESET (1 << (16 + 7))     // BSRR 重置 PB7

// LED4 (PB8) 配置 - 蓝色LED2
#define GPIOB_MODE_PIN8_OUT (0x01 << (8 * 2))     // MODER8[1:0] = 01 (输出)
#define GPIOB_OTYPE_PIN8_PP (0x00 << 8)           // OT8 = 0 (推挽)
#define GPIOB_OSPEED_PIN8_MID (0x01 << (8 * 2))   // OSPEEDR8[1:0] = 01 (中速)
#define GPIOB_PUPDR_PIN8_NOPUPD (0x00 << (8 * 2)) // PUPDR8[1:0] = 00 (无上下拉)
#define GPIOB_BSRR_PIN8_SET (1 << 8)              // BSRR 设置 PB8
#define GPIOB_BSRR_PIN8_RESET (1 << (16 + 8))     // BSRR 重置 PB8

// LED5 (PB14) 配置 - 红色LED1
#define GPIOB_MODE_PIN14_OUT (0x01 << (14 * 2))     // MODER14[1:0] = 01 (输出)
#define GPIOB_OTYPE_PIN14_PP (0x00 << 14)           // OT14 = 0 (推挽)
#define GPIOB_OSPEED_PIN14_MID (0x01 << (14 * 2))   // OSPEEDR14[1:0] = 01 (中速)
#define GPIOB_PUPDR_PIN14_NOPUPD (0x00 << (14 * 2)) // PUPDR14[1:0] = 00 (无上下拉)
#define GPIOB_BSRR_PIN14_SET (1 << 14)              // BSRR 设置 PB14
#define GPIOB_BSRR_PIN14_RESET (1 << (16 + 14))     // BSRR 重置 PB14

// LED6 (PB15) 配置 - 红色LED2
#define GPIOB_MODE_PIN15_OUT (0x01 << (15 * 2))     // MODER15[1:0] = 01 (输出)
#define GPIOB_OTYPE_PIN15_PP (0x00 << 15)           // OT15 = 0 (推挽)
#define GPIOB_OSPEED_PIN15_MID (0x01 << (15 * 2))   // OSPEEDR15[1:0] = 01 (中速)
#define GPIOB_PUPDR_PIN15_NOPUPD (0x00 << (15 * 2)) // PUPDR15[1:0] = 00 (无上下拉)
#define GPIOB_BSRR_PIN15_SET (1 << 15)              // BSRR 设置 PB15
#define GPIOB_BSRR_PIN15_RESET (1 << (16 + 15))     // BSRR 重置 PB15

// 工具宏

#define SET_BIT(REG, BIT) ((REG) |= (BIT))
#define RESET_BIT(REG, BIT) ((REG) &= ~(BIT))

// GPIO 初始化函数声明
void GPIO_Ini_1(void);
void GPIO_Ini_2(void);

#endif // INIT_H
