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
		gotoxy(0, 0);
		unsigned char foreground = 0, background = 0;
		pokeb(0xB800, 0, 'A'); //make an A sign on screen 
		pokeb(0xB800, 1, 6); // with a 0x0F foreground 
		//textbackground(5);
		gotoxy(0, 1);
		//delay(1000);
		//textbackground(RED);
		//pokeb(0xB800, 1, 1);
		do
		{
			c = inportb(0x60); //take an input from keyboard when it is hit
			delay(100);
			if (c == 1) //escape = quit program
			{
				textbackground(BLACK);
				clrscr();
				return 0;
			}
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
			else if (c == 43)
			{

				foreground++;
				if (foreground == 15) foreground = 0;
				//change foreground
				pokeb(0xB800 + i, 1, foreground);
			}
			else if (c == 45) //change background colour
			{
				background++;
				if (background == 15) background = 0;
				textbackground(background);
			}
			else
				{
					//pokeb(0xB800+i, 0, c);
					//pokeb(0xB800+i, 1, foreground);
					//pokeb(0xB800+i, 4, background);
					i=i+2;
				}
		} while (kbhit());
		//getch();
	}
	//_setcursortype(_NORMALCURSOR); //set back to normald
	//return 0;
}

