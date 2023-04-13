#include <iostream.h>
#include <conio.h>
#include <dos.h>


int main()
{
    unsigned char scan_code;
    cout << " Press any key..." << endl;
    while (1)
	{
		scan_code = inportb(0x60);
        delay(100);
        if (scan_code == 0x48) {
            cout << "Up Arrow" << endl;
        }
        else if (scan_code == 0x50) {
            cout << "Down Arrow" << endl;
        }
        else if (scan_code == 0x4B) {
            cout << "Left Arrow" << endl;
        }
        else if (scan_code == 0x4D) {
            cout << "Right Arrow" << endl;
        }
        else
            cout << " Code of this button: " << scan_code << endl;
	}
}