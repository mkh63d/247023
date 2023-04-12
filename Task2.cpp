#include <iostream.h>
#include <dos.h>
#include <conio.h>

int main()
{
	while (1)
	{
		unsigned char c;
		clrscr();
		//_setcursortype(_NOCURSOR); //switch off a coursor
		textbackground(RED); //set a new background
		int x = 0, y = -1, i =0;
		gotoxy(0, -1);
		pokeb(0xB800, 0, 'A'); //make an A sign on screen 
		pokeb(0xB800, 1, 0xFA); // with a 0x0F foreground 

		do
		{
			c = inportb(0x60); //take an input from keyboard when it is hit
			if(c==0x1B) //escape = quit program
				return 0;
			else if (c == 0x48)
			{
				if (y > -1) gotoxy(x, y - 1);	//goes up
			}
			else if (c == 0x4B)
			{
				if (x > 0) gotoxy(x - 1, y);	//goes left 
			}
			else if (c == 0x4D)
			{
				if (x < 81) gotoxy(x + 1, y);	//goes right
			}
			else if (c == 0x50)
			{
				if (y < 26) gotoxy(x, y + 1);	//goes down
			}
			else if (c == '+')
			{
				//change foreground
			}
			else if (c== '-')
				textbackground(0x01);
			else
				{
					pokeb(0xB800, 0, c);
					pokeb(0xB800, 1, c);
					//i++;
				}
		} while (kbhit());
		//getch();
	}
	//_setcursortype(_NORMALCURSOR); //set back to normald
	//return 0;
}

