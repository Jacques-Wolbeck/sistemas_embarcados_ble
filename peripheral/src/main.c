#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/types.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>
#include <kernel.h>
#include <ble_application.h>
#include <ble_service.h>

static void on_ble_rx_data(const uint8_t *buffer, size_t len) {
    //printk("Init (on_ble_rx_data)");
    ble_uart_service_transmit(buffer, len);
    //printk("End (on_ble_rx_data) \n");
}

static void on_ble_stack_ready(struct bt_conn *conn) {
    //printk(" Init (on_ble_stack_ready) \n");
    (void)conn;
    ble_uart_service_register(on_ble_rx_data);
    //printk(" End (on_ble_stack_ready)\n");
}

void main (void) {
    //printk(" Init (ble application start) \n");
    ble_application_start(on_ble_stack_ready);
    //printk(" End (ble_application_start)\n");
}

//$peripheral_bin?=@C:\Users\jacqu\Documents\PlatformIO\Projects\peripheral\.pio\build\nrf52840_dk\firmware.elf