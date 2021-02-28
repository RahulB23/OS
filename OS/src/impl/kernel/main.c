#include"print.h"

void kernel_main()
{
	print_clear();
	print_set_color(PRINT_WHITE, PRINT_BLACK);
	print_string("In C: boot passed");

}