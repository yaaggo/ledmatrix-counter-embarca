#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/bootrom.h"

#include "include/matrix.h"
#include "include/button.h"

#define INCREMENT 50
#define LED_RED_PIN 13

int main() {
    uint16_t time = 200;
    uint16_t time_to_switch_off = 0;

    stdio_init_all();

    // inicializando botao
    button_init(BUTTON_A_PIN);
    button_init(BUTTON_B_PIN);

    // inicializando matriz
    matrix_init(MATRIX_LED_PIN);
    matrix_number(0, COLOR_RGB(1, 1, 1));

    // inicializando led vermelho
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_put(LED_RED_PIN, false);

    while(true) {

        // atualiza a matriz
        matrix_update();
        sleep_ms(INCREMENT);

        time += INCREMENT;
        time_to_switch_off += INCREMENT;

        // lógica para ficar piscando o led
        if(time >= 200) {
            gpio_put(LED_RED_PIN, true);
            sleep_ms(INCREMENT);
            gpio_put(LED_RED_PIN, false);
            time = INCREMENT;
        }
        // lógica a mais para poder entrar em modo bootsel após 15 segundos
        if(time_to_switch_off == 15000) {
            matrix_clear();
            matrix_update();
            gpio_put(LED_RED_PIN, false);
            reset_usb_boot(0, 0);
        }   
    }
}
