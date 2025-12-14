#include <esp_log.h>
#include <ssd1306.h>
#include <stdio.h>

void app_main(void) {
  init_ssd1306();

  while (1) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
