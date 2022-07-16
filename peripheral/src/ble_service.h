#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>
#include <stdio.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>
#include <kernel.h>
#include <ble_application.h>

typedef void (*ble_uart_service_rx_callback) (const uint8_t *data, size_t length);
int ble_uart_service_register(const ble_uart_service_rx_callback callback);
int ble_uart_service_transmit(const uint8_t *buffer, size_t len);