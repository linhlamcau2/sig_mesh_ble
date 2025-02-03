#include "rd_log.h"

static char out[512];

unsigned char uart_CSend(char* data){		//RD_EDIT: uart_Csend
	#if (HCI_ACCESS == HCI_USE_UART)
	while(*data != '\0')
	{
		uart_ndma_send_byte(*(data++));
	}
	#endif
	return 0;
}

void rd_log_ev(const char *format, ...) {
	va_list args;
	va_start(args, format);
	vsnprintf(out, 1024, format, args);
	va_end(args);
//	print(&out, format, args);
	uart_CSend(out);
//	free(out);
}
