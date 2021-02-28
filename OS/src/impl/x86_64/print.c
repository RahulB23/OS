#include"print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char{
	uint8_t character;
	uint8_t color;
};

struct Char* buffer = (struct Char*)0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_WHITE | (PRINT_BLACK << 4);	// white text on black background

void clear_row(size_t row)
{
	struct Char empty_char = (struct Char){
		character : 0x20,
		color : color,
	};

	for(size_t cols=0; cols<NUM_COLS; cols++)
	{
		buffer[cols + row*NUM_COLS] = empty_char;
	}
	return;

}

void print_clear()
{
	for(size_t i=0; i<NUM_ROWS; i++)
	{
		clear_row(i);
	}

	row = 0;	//init to start
	col = 0;
	return;
}

void print_newline()
{
	col = 0;

	//If not last row then go to next row
	if(row < NUM_ROWS - 1)
	{
		row++;
		return;
	}

	//if was last row then shift everything up by one row and set cursor to last row
    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_ROWS - 1);
    row = NUM_ROWS - 1;
    col = 0;
	return;
}

void print_char(char character)
{
	if(character == '\n')
	{
		print_newline();
		return;
	}

	if(col > NUM_COLS)
	{
		print_newline();		
	}

	buffer[col + NUM_COLS*row] = (struct Char){
		character: (uint8_t)character,
		color: color
	};

	col++;
	return;
}

void print_string(char* string)
{
	for(size_t i = 0; 1; i++)
	{
		uint8_t character = (uint8_t) string[i]; 

		if(character == 0x00)
		{
			return;
		}

		print_char((char)character); 
	}
	return;
}

void print_set_color(uint8_t foreground, uint8_t background)
{
	color = (foreground | (background << 4));
	return;
}