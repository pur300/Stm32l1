#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "math.h"
#include "stm32l1xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "string.h"
#include "structures.h"

extern QueueHandle_t bluetooth_clockQ;
extern QueueHandle_t bluetooth_displayQ;
extern QueueHandle_t ISR_bluetoothQ;

// Notification message defines
#define NEW_SMS_STR "N_SMS"
#define NEW_MISSED_CALL_STR "N_M_CALL"
#define NEW_EMAIL_STR "N_EMAIL"
#define CURRENT_TIME_STR "T"

#define APB2_FREQ 32000000.0

// GPIO MODER register offsets and values
#define BT_MODER9_OFFSET 0x12
#define BT_MODER9_VALUE 0x2
#define BT_MODER10_OFFSET 0x14
#define BT_MODER10_VALUE 0x2
// GPIO OSPEEDR register offsets and values
#define BT_OSPEEDR9_OFFSET 0x12
#define BT_OSPEEDR9_VALUE 0x2
#define BT_OSPEEDR10_OFFSET 0x14
#define BT_OSPEEDR10_VALUE 0x2
// GPIO PUPDR register offsets and values
#define BT_PUPDR9_OFFSET 0x12
#define BT_PUPDR9_VALUE 0x1
#define BT_PUPDR10_OFFSET 0x14
#define BT_PUPDR10_VALUE 0x1
// GPIO AFRH register offsets and values
#define BT_AFRH9_OFFSET 0x4
#define BT_AFRH9_VALUE 0x7
#define BT_AFRH10_OFFSET 0x8
#define BT_AFRH10_VALUE 0x7

// NVIC ISER1 register offsets and values
#define BT_RS4_OFFSET (USART1_IRQn % 32)
#define BT_RS4_VALUE 0x1
// NVIC IP register offsets and values
#define BT_IP4_OFFSET USART1_IRQn // Priority
#define BT_IP4_VALUE 0x2 // Priority

// USART CR1 register offsets and values
#define BT_OVER8_OFFSET 0xF
#define BT_OVER8_VALUE 0x1
#define BT_TE_OFFSET 0x3
#define BT_TE_VALUE 0x1
#define BT_RE_OFFSET 0x2
#define BT_RE_VALUE 0x1
#define BT_UE_OFFSET 0xD
#define BT_UE_VALUE 0x1
#define BT_RXNEIE_OFFSET 0x5
#define BT_RXNEIE_VALUE 0x1

// TIM4 CR1 register offsets and values
#define BT_CEN_OFFSET 0x0
#define BT_CEN_VALUE 0x1
#define BT_URS_OFFSET 0x2
#define BT_URS_VALUE 0x1
// TIM4 PSC register value
#define BT_PSC_VALUE 0x7D00
// TIM4 EGR register offsets and values
#define BT_UG_OFFSET 0x0
#define BT_UG_VALUE 0x1

void bluetooth_t(void);
void bluetooth_peripheralInit(uint32_t baudrate);
void USART1_IRQHandler(void);

#endif
