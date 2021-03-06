#ifndef MAIN_H
#define MAIN_H

#include "math.h"
#include "stm32l1xx.h"
#include "sensors.h"
#include "display.h"
#include "clock.h"
#include "battery.h"
#include "button.h"
#include "bluetooth.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "messages.h"

// SCB AIRCR register offsets and values
#define PRIGROUP_OFFSET 0x8
#define PRIGROUP_VALUE 0x3
#define VECTKEY_OFFSET 0x10
#define VECTKEY_VALUE 0x5FA

void main(void);

#endif
