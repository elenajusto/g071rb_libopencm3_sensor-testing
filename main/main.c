
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>


const char data[] = "Hello world\n";

int main(void) {

	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_USART2);

	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5); // PA5: LED
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);    // PA2: USART2_TX on Nucleo board
	gpio_set_af(GPIOA, GPIO_AF1, GPIO2);

	usart_set_baudrate(USART2, 115200);
	usart_set_mode(USART2, USART_MODE_TX);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_enable(USART2);

	while (1) {

        // flash LED
		gpio_toggle(GPIOA, GPIO5);

        // crude delay
		for (int i = 0; i < 100000; i++)
			__asm__("nop"); 

        // send string over USART
		for (const char *p = data; *p; ++p)
			usart_send_blocking(USART2, *p);
	}
	return 0;
}
