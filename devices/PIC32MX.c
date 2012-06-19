/**
 *
 */

/*

	Copyright (c) 2012 Andy Gock

	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
	CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
	TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */
#include "../glcd.h"

#if defined(GLCD_DEVICE_PIC32MX)

void glcd_init(void)
{
#if defined(GLCD_CONTROLLER_PCD8544)
	// set pin directions
	
	// Set MOSI, Master SS, SCK to output (otherwise SPI won't work)
	// must be done even if native SS pin not used
	// ...
		
	// set SS, DC and RST pins to output
	// ...
	
	// deselect LCD
	GLCD_DESELECT();

	// set up SPI
	// ...
	
	glcd_reset();
	
	// get into the EXTENDED mode!
	glcd_command(PCD8544_FUNCTION_SET | PCD8544_EXTENDED_INSTRUCTION);

	// LCD bias select (4 is optimal?)
	glcd_command(PCD8544_SET_BIAS | 0x2);
	
	// set VOP
	glcd_command(PCD8544_SET_VOP | 50); // Experimentally determined
	
	// back to standard instructions
	glcd_command(PCD8544_FUNCTION_SET); 
	
	// normal mode
	glcd_command(PCD8544_DISPLAY_CONTROL | PCD8544_DISPLAY_NORMAL);

	glcd_select_screen((uint8_t *)&glcd_buffer,&glcd_bbox);
	
	glcd_clear();
#else
	
#endif /* GLCD_CONTROLLER_PCD8544 */
}

void glcd_spi_write(uint8_t c)
{
	GLCD_SELECT();

	GLCD_DESELECT();	
}

void glcd_reset(void)
{
	// toggle RST low to reset. Minimum pulse 100ns on datasheet.
	GLCD_SELECT();
	GLCD_RESET_LOW();
	_delay_ms(100);
	GLCD_RESET_HIGH();
	GLCD_DESELECT();	
}

#endif