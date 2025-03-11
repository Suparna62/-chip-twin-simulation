#include <stdint.h>

#define LED_PIN (1U << 13)
#define GPIOC_BASE  (0x40011000U)
#define RCC_BASE    (0x40021000U)

#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIOC_CRH   (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR   (*(volatile uint32_t *)(GPIOC_BASE + 0x0C))

void delay(uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        __asm("nop");
    }
}

int main(void) {
    RCC_APB2ENR |= (1U << 4);
    GPIOC_CRH &= ~(0xF << 20);
    GPIOC_CRH |=  (0x1 << 20);
    while (1) {
        GPIOC_ODR ^= LED_PIN;
        delay(1000000);
    }
}
