// STM32G071RB mikrodenetleyicisinin register tanımları
#define RCC_BASE        0x40021000
#define RCC_IOPENR      (*(volatile unsigned int *)(RCC_BASE + 0x34))
#define RCC_AHBENR		(*(volatile unsigned int *)(RCC_BASE + 0x38))
#define GPIOA_BASE      0x50000000
#define GPIOA_MODER     (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile unsigned int *)(GPIOA_BASE + 0x14))
#define GPIOAEN         (1U << 0)
#define PIN0            (1U << 0)
#define LED_PIN         PIN0



int main(void) {
    // System Clock ayarları

	RCC_AHBENR |= 0x1;

    RCC_IOPENR |= GPIOAEN;  // RCC_IOPENR_IOPAEN

    // PA0 pinini çıkış olarak ayarlama
    GPIOA_MODER &= (1U << (2 * 0));


    while (1) {
        // LED'i yak
        GPIOA_ODR |= LED_PIN;
        delay_ms(500);

        // LED'i söndür
        GPIOA_ODR &= ~LED_PIN;
        delay_ms(500);
    }
}


