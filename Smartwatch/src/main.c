#include "main.h"

// All queues
QueueHandle_t battery_displayQ;
QueueHandle_t button_displayQ;
QueueHandle_t sensor_displayQ;
QueueHandle_t clock_displayQ;
QueueHandle_t bluetooth_clockQ;
QueueHandle_t bluetooth_displayQ;
QueueHandle_t ISR_bluetoothQ;

void main(void){

    /* SCB configuration */

    // Set AIRCR register(
    SCB->AIRCR = (VECTKEY_VALUE << VECTKEY_OFFSET) | (PRIGROUP_VALUE << PRIGROUP_OFFSET);

    // Initialize all peripherals
    display_peripheralInit();
    sensors_peripheralInit();
    clock_peripheralInit();
    button_peripheralInit();
    battery_peripheralInit();
    bluetooth_peripheralInit(9600);
    

    // Initialize all queues
    battery_displayQ = xQueueCreate(3, sizeof(uint8_t));
    button_displayQ = xQueueCreate(3, sizeof(uint8_t));
    sensor_displayQ = xQueueCreate(3, sizeof(Sensor));
    clock_displayQ = xQueueCreate(3, sizeof(Time));
    bluetooth_clockQ = xQueueCreate(3, sizeof(Time));
    bluetooth_displayQ = xQueueCreate(5, sizeof(Message));
    ISR_bluetoothQ = xQueueCreate(30, sizeof(uint8_t));

    // Create battery_t task
    xTaskCreate(battery_t, "Battery task", 1000, NULL, tskIDLE_PRIORITY + 2, NULL);
    // Create sensor_t task
    xTaskCreate(sensors_t, "Sensor task", 1000, NULL, tskIDLE_PRIORITY + 2, NULL);
    // Create bluetooth_t task
    //xTaskCreate(bluetooth_t, "Bluetooth task", 1000, NULL, tskIDLE_PRIORITY + 2, NULL);
    // Create clock_t task
    xTaskCreate(clock_t, "Clock task", 1000, NULL, tskIDLE_PRIORITY + 3, NULL);
    // Create display_t task
    xTaskCreate(display_t, "Display task", 1000, NULL, tskIDLE_PRIORITY + 1, NULL);

    // Start scheduler
    vTaskStartScheduler();
    for(;;);

}
