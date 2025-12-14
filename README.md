# SSD1306 OLED Display Driver for ESP32

This project demonstrates how to control an SSD1306 OLED display (128x64 pixels) using an ESP32 microcontroller over the I2C interface with the ESP-IDF framework.

## Hardware Required

*   **ESP32 Development Board**
*   **SSD1306 OLED Display** (I2C interface)

## Pin Configuration (Default)

The default I2C pin configuration is defined in `main/ssd1306.c`:

| ESP32 Pin | SSD1306 Pin | Function |
| :--- | :--- | :--- |
| **GPIO 6** | SDA | Serial Data |
| **GPIO 7** | SCL | Serial Clock |
| 3.3V | VCC | Power |
| GND | GND | Ground |

*Note: The I2C address is set to `0x3C` by default.*

## Build and Flash

To build and flash the project to your ESP32, use the standard ESP-IDF commands:

1.  **Set the target (if not already set):**
    ```bash
    idf.py set-target esp32c6
    ```
    *(Or esp32s3, esp32c3, etc., depending on your board. Note that the default pins GPIO 6/7 might need to be changed for other chips).*

2.  **Build the project:**
    ```bash
    idf.py build
    ```

3.  **Flash and monitor:**
    ```bash
    idf.py -p PORT flash monitor
    ```
    *(Replace `PORT` with your actual serial port).*

## File Structure

*   `main/main.c`: Main application entry point. Initializes the display and runs a demo loop.
*   `main/ssd1306.h`: Header file containing the driver API and type definitions.
*   `main/ssd1306.c`: Implementation of the SSD1306 driver.
*   `main/ssd1306_const.h`: Constants, commands, and font data (8x8 ASCII).

## API Overview

The driver provides a high-level API for basic usage and a lower-level API for more control.

### Basic Usage

*   `void init_ssd1306(void)`: Initializes the I2C master and the SSD1306 display with default settings.
*   `esp_err_t ssd1306_print_str(uint8_t x, uint8_t y, const char *text, bool invert)`: Prints a string at the specified coordinates.
*   `esp_err_t ssd1306_display(void)`: Updates the physical display with the content of the internal buffer.

### Advanced Usage (Low-Level)

*   `i2c_ssd1306_init(...)`: Initialize with custom configuration.
*   `i2c_ssd1306_buffer_clear(...)`: Clear the internal buffer.
*   `i2c_ssd1306_buffer_fill_pixel(...)`: Set/clear a single pixel.
*   `i2c_ssd1306_buffer_image(...)`: Draw a bitmap image.
*   `i2c_ssd1306_buffer_int(...)`: Helper to print integers.
*   `i2c_ssd1306_buffer_float(...)`: Helper to print floating-point numbers.

See `main/ssd1306.h` for the full list of functions and documentation.

## Example Output

The default `main.c` displays "Hello World!", "SSD1306 OLED", and other text strings, updating every 3 seconds.
