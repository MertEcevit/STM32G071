#include <stdint.h>
// STM32G071RB için gerekli clock GPIO pin register tanımlamaları
#define RCC_BASE        0x40021000
#define RCC_IOPENR      (*(volatile unsigned int *)(RCC_BASE + 0x34))
#define RCC_AHBENR      (*(volatile unsigned int *)(RCC_BASE + 0x38))

#define GPIOA_BASE      0x50000000
#define GPIOA_MODER     (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile unsigned int *)(GPIOA_BASE + 0x14))

#define GPIOAEN         (1U << 0)
#define PIN0            (1U << 0)
#define LED_PIN         PIN0

#define DELAY_COUNT     8000000  // 500ms gecikme için yaklaşık değer

void delay(volatile uint32_t count) {
    while (count--) {
        // Boş döngü ile gecikme
    }
}

int main(void) {

    RCC_IOPENR |= GPIOAEN;  // GPIOA'nın clock'u etkinleştiriliyor


    GPIOA_MODER &= ~(3U << (2 * 0));
    GPIOA_MODER |= (1U << (2 * 0));   // PA0'u çıkış modu olarak ayarladık

    while (1) {
        // LED'i yak
        GPIOA_ODR |= LED_PIN;
        delay(DELAY_COUNT);

        // LED'i söndür
        GPIOA_ODR &= ~LED_PIN;
        delay(DELAY_COUNT);
    }
}
