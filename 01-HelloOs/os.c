#include <stdint.h>

#define UART        0x10000000
#define UART_THR    (uint8_t*)(UART+0x00) // THR:transmitter holding register
#define UART_LSR    (uint8_t*)(UART+0x05) // LSR:line status register
#define UART_LSR_EMPTY_MASK 0x40          // LSR Bit 6: Transmitter empty; both the THR and LSR are empty

int lib_putc(char ch) {
	while ((*UART_LSR & UART_LSR_EMPTY_MASK) == 0);
	return *UART_THR = ch;
}

void lib_puts(char *s) {
	while (*s) lib_putc(*s++);
}

int programa_alumno() {
    int a = 10;
    int b = 20;
    int resultado = suma_asm(a, b);
    return 0;
}

int os_main(void)
{
	lib_puts("Hello OS!\n");
	programa_alumno();
	while (1) {}
	return 0;
}
