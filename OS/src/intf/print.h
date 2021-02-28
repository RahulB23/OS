#pragma once
#include<stdint.h>
#include<stddef.h>

enum {

	PRINT_BLACK = 0,
	PRINT_BLUE = 1,
	PRINT_GREEN = 2,
	PRINT_CYAN = 3,
	PRINT_RED = 4,
	PRINT_MAGENTA = 5,
	PRINT_BROWN = 6,
	PRINT_LIGHTGRAY = 7,
	PRINT_DARKGRAY = 8,
	PRINT_LIGHTBLUE = 9,
	PRINT_LIGHTGREEN = 10,
	PRINT_LIGHTCYAN = 11,
	PRINT_LIGHTRED = 12,
	PRINT_PINK = 13,
	PRINT_YELLOW = 14,
	PRINT_WHITE = 15,

};

void print_clear();
void print_char(char character);
void print_string(char* string);
void print_set_color(uint8_t foreground, uint8_t background);
