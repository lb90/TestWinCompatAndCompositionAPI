#define NTDDI_VERSION NTDDI_WIN7
#include <sdkddkver.h>
#include <windows.h>
#include <dwmapi.h>
#include <uxtheme.h>

#include <string>
#include <sstream>

#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "uxtheme.lib")

void CheckDwmIsCompositionEnabled() {
	BOOL val = FALSE;
	HRESULT ret = DwmIsCompositionEnabled(&val);
	std::wstringstream s;
	s << L"DwmIsCompositionEnabled - value: " << val << L", return: " << ret;

	MessageBoxW(NULL, s.str().c_str(), L"Info", MB_OK | MB_ICONINFORMATION);
}

void CheckIsCompositionActive() {
	BOOL ret = IsCompositionActive();
	std::wstringstream s;
	s << L"IsCompositionActive - value: " << ret;

	MessageBoxW(NULL, s.str().c_str(), L"Info", MB_OK | MB_ICONINFORMATION);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR lpCmdLine, int nShowCmd)
{
	CheckDwmIsCompositionEnabled();
	CheckIsCompositionActive();

	return 0;
}