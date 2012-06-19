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

#ifndef PIC32MX_H_
#define PIC32MX_H_

#include <stdint.h>

#if defined(GLCD_DEVICE_PIC32MX)

/* Swap 2 integers around */
#define swap(a, b) { uint8_t t = a; a = b; b = t; }

/* Define pin mappings */
// ...

/* Need to define these below for PIC32MX */
#define GLCD_SELECT()     
#define GLCD_DESELECT()   
#define GLCD_DC_LOW()     
#define GLCD_DC_HIGH()    
#define GLCD_RESET_LOW()  
#define GLCD_RESET_HIGH() 

#endif /* GLCD_DEVICE_PIC32MX */

#endif /* PIC32MX_H_ */
