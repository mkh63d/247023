#include <iostream.h>
#include <dos.h>
#include <conio.h>

int main()
{
    unsigned char c;
    clrscr();
	_setcursortype(_NOCURSOR); //switch off a coursor
	textbackground(RED); //set a new background
	int x = 0, y = -1;
	gotoxy(0, -1);
	pokeb(0xB800, 0, 'A'); //make an A sign on screen 
	pokeb(0xB800, 1, 0x0F); // with a 0x0F foreground 

	do
	{
		c = inportb(0x60); //take an input from keyboard when it is hit
		switch (c)
		{
		case 0x1B: //escape = quit program
			break;
		case 0x48:
			if (y > -1) gotoxy(x, y - 1);	//goes up
		case 0x4B:
			if (x > 0) gotoxy(x - 1, y);	//goes left 
		case 0x4D:
			if (x < 81) gotoxy(x + 1, y);	//goes right
		case 0x50:
			if (y < 26) gotoxy(x, y + 1);	//goes down
		case '+':
			//change foreground
		case '-':
			textbackground(0x01);
		}
	} while (_kbhit());
	//getch();

	_setcursortype(_NORMALCURSOR); //set back to normal
	return 0;
}

