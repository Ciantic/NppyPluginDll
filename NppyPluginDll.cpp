/**
 * NppyPluginDll
 * 
 * General DLL plugins for Python
 * 
 * Created by Jari Pennanen in May 2011
 * I hereby place this to public domain.
 *
 **/

#include "stdafx.h"
// #include <iostream>
#include <vector>
#include <string>
#include "NppyPluginDll.h"
#include "NotepadPlusPlus/PluginInterface.h"
#include "NotepadPlusPlus/NppPythonScript.h"

using namespace std;

#define PYINITLAZY() if (!is_pluginInited) initPyPlugin();

// Is the python plugin initialized?
bool is_pluginInited = FALSE;
bool has_pythonScript = TRUE;

// Python Plugin diretory
wstring pluginDirectory;

// Python Plugin INI
wstring pluginIni;

// Plugin details
wstring pluginImports;
wstring pluginName = TEXT("My Plugin");
wstring pluginAbout = TEXT("Created by Foo Bar");
wstring pluginAboutTitle /* = pluginName */;

// Npp handles etc.
NppData nppData;


void runPython(wstring script, int messageType)
{
    if (!has_pythonScript)
		return;

    PythonScript_Exec pse;
    pse.structVersion = 1;

    pse.completedEvent = NULL;
    pse.deliverySuccess = FALSE;
    pse.flags = 0;
	pse.script = script.c_str();

    TCHAR pluginName[] = TEXT("PythonScript.dll");
    CommunicationInfo commInfo;
    commInfo.internalMsg = messageType;
	commInfo.srcModuleName = pluginName; // TODO: Not exactly the DLL name!

    commInfo.info = reinterpret_cast<void*>(&pse);

    BOOL delivery = SendMessage(nppData._nppHandle, NPPM_MSGTOPLUGIN, reinterpret_cast<WPARAM>(pluginName), reinterpret_cast<LPARAM>(&commInfo));
    if (!delivery)
    {
        MessageBox(NULL, TEXT("Python Script Plugin not found.  Please install the Python Script plugin from Plugin Manager"), pluginName, 0);
        has_pythonScript = false;
    }
    else if (!pse.deliverySuccess)
    {
		MessageBox(NULL, TEXT("Python Script Plugin did not accept the script"), pluginName, 0);
        has_pythonScript = false;
    }
}

// Initialize python plugin
void initPyPlugin()
{
	wstring syspath = wstring(TEXT("sys.path.append('")) + pluginDirectory + wstring(TEXT("')"));
	wstring imports;
	if (!pluginImports.empty())
		imports = wstring(TEXT("import ")) + pluginImports;

	runPython(syspath, PYSCR_EXECSTATEMENT);
	runPython(imports, PYSCR_EXECSTATEMENT);
}

void runPython(wstring stmt)
{
	PYINITLAZY();
	runPython(stmt, PYSCR_EXECSTATEMENT);
}


// Function items in Plugin menu
vector<FuncItem> funcItems;

// Wondering what is this shit? See e.g.
// http://stackoverflow.com/questions/5962960/how-can-i-cast-or-convert-boost-bind-to-c-function-pointer
// 
// Long story short: C++ does not allow to create functions or 
// lambda functions with valid C function pointers runtime
// 
// 64 oughta be enough for everybody!
#define MAX_FUNCS 64
vector<wstring> funcStatements;
void func0() { runPython(funcStatements[0]); }
void func1() { runPython(funcStatements[1]); }
void func2() { runPython(funcStatements[2]); }
void func3() { runPython(funcStatements[3]); }
void func4() { runPython(funcStatements[4]); }
void func5() { runPython(funcStatements[5]); }
void func6() { runPython(funcStatements[6]); }
void func7() { runPython(funcStatements[7]); }
void func8() { runPython(funcStatements[8]); }
void func9() { runPython(funcStatements[9]); }
void func10() { runPython(funcStatements[10]); }
void func11() { runPython(funcStatements[11]); }
void func12() { runPython(funcStatements[12]); }
void func13() { runPython(funcStatements[13]); }
void func14() { runPython(funcStatements[14]); }
void func15() { runPython(funcStatements[15]); }
void func16() { runPython(funcStatements[16]); }
void func17() { runPython(funcStatements[17]); }
void func18() { runPython(funcStatements[18]); }
void func19() { runPython(funcStatements[19]); }
void func20() { runPython(funcStatements[20]); }
void func21() { runPython(funcStatements[21]); }
void func22() { runPython(funcStatements[22]); }
void func23() { runPython(funcStatements[23]); }
void func24() { runPython(funcStatements[24]); }
void func25() { runPython(funcStatements[25]); }
void func26() { runPython(funcStatements[26]); }
void func27() { runPython(funcStatements[27]); }
void func28() { runPython(funcStatements[28]); }
void func29() { runPython(funcStatements[29]); }
void func30() { runPython(funcStatements[30]); }
void func31() { runPython(funcStatements[31]); }
void func32() { runPython(funcStatements[32]); }
void func33() { runPython(funcStatements[33]); }
void func34() { runPython(funcStatements[34]); }
void func35() { runPython(funcStatements[35]); }
void func36() { runPython(funcStatements[36]); }
void func37() { runPython(funcStatements[37]); }
void func38() { runPython(funcStatements[38]); }
void func39() { runPython(funcStatements[39]); }
void func40() { runPython(funcStatements[40]); }
void func41() { runPython(funcStatements[41]); }
void func42() { runPython(funcStatements[42]); }
void func43() { runPython(funcStatements[43]); }
void func44() { runPython(funcStatements[44]); }
void func45() { runPython(funcStatements[45]); }
void func46() { runPython(funcStatements[46]); }
void func47() { runPython(funcStatements[47]); }
void func48() { runPython(funcStatements[48]); }
void func49() { runPython(funcStatements[49]); }
void func50() { runPython(funcStatements[50]); }
void func51() { runPython(funcStatements[51]); }
void func52() { runPython(funcStatements[52]); }
void func53() { runPython(funcStatements[53]); }
void func54() { runPython(funcStatements[54]); }
void func55() { runPython(funcStatements[55]); }
void func56() { runPython(funcStatements[56]); }
void func57() { runPython(funcStatements[57]); }
void func58() { runPython(funcStatements[58]); }
void func59() { runPython(funcStatements[59]); }
void func60() { runPython(funcStatements[60]); }
void func61() { runPython(funcStatements[61]); }
void func62() { runPython(funcStatements[62]); }
void func63() { runPython(funcStatements[63]); }
PFUNCPLUGINCMD funcs[] = { 
	func0, func1, func2, func3, func4, func5, func6, func7, func8, func9, func10, func11, func12, func13, func14, func15, func16, func17, func18, func19, func20, func21, func22, func23, func24, func25, func26, func27, func28, func29, func30, func31,
	func32, func33, func34, func35, func36, func37, func38, func39, func40, func41, func42, func43, func44, func45, func46, func47, func48, func49, func50, func51, func52, func53, func54, func55, func56, func57, func58, func59, func60, func61, func62, func63
};


// Add command menu function for plugin
void addFunction(const TCHAR *functionName, 
		PFUNCPLUGINCMD function,
		UCHAR key,
		int modifiers,
		bool initToChecked)
{
	ShortcutKey *shkey = NULL;
	if (key) {
		shkey = new ShortcutKey();
		shkey->_key = key;
		shkey->_isCtrl = (modifiers & MOD_CONTROL) == MOD_CONTROL;
		shkey->_isAlt = (modifiers & MOD_ALT) == MOD_ALT;
		shkey->_isShift = (modifiers & MOD_SHIFT) == MOD_SHIFT;
	}

	FuncItem *item = new FuncItem();
	lstrcpy(item->_itemName, functionName);
	item->_pFunc = function;
	item->_init2Check = initToChecked;
	item->_pShKey = shkey;

	funcItems.push_back(*item);	
}

// Add command menu function for plugin
void addFunction(const TCHAR *functionName, 
		PFUNCPLUGINCMD function)
{
	addFunction(functionName, function, 0, 0, 0);
}

// Hard coded about box
void about()
{
	MessageBox(NULL, pluginAbout.c_str(), pluginAboutTitle.c_str(), MB_OK);
}

// Read [plugin] section of ini
void readPluginDetailsIni()
{
	// Get [plugin] "imports" key
	WCHAR pluginImports_[4096];
	GetPrivateProfileString(TEXT("plugin"), TEXT("imports"), TEXT(""), pluginImports_, 4096, pluginIni.c_str());
	pluginImports = pluginImports_;

	// Get [plugin] "name" key
	WCHAR pluginName_[256];
	GetPrivateProfileString(TEXT("plugin"), TEXT("name"), pluginName.c_str(), pluginName_, 256, pluginIni.c_str());
	pluginName = pluginName_;

	// Get [plugin] "about" key
	WCHAR pluginAbout_[4096];
	GetPrivateProfileString(TEXT("plugin"), TEXT("about"), pluginAbout.c_str(), pluginAbout_, 4096, pluginIni.c_str());
	pluginAbout = pluginAbout_;

	// Get [plugin] "about title" key (Defaults to "About " + pluginName)
	WCHAR pluginAboutTitle_[256];
	GetPrivateProfileString(TEXT("plugin"), TEXT("about title"), (TEXT("About ") + pluginName).c_str(), pluginAboutTitle_, 256, pluginIni.c_str());
	pluginAboutTitle = pluginAboutTitle_;
}

// Read [funcNNN] sections of ini
void readPluginFuncsIni()
{
	WCHAR sectionNames[4096];
	GetPrivateProfileSectionNames(sectionNames, 4096, pluginIni.c_str());
	int i = 0;

	// Loop over [func1], [func2], ...
	for (WCHAR* secName = sectionNames; *secName; secName += lstrlen(secName) + 1) {
		wstring sectionName = wstring(secName);

		// Only sections beginning "func"
		if (sectionName.substr(0, 4) != TEXT("func"))
			continue;

		// If is separator
		if (GetPrivateProfileInt(secName, TEXT("separator"), 0, pluginIni.c_str())) {
			addFunction(TEXT("\0"), NULL);
			continue;
		}

		// Get function details
		WCHAR funcName[256];
		WCHAR execStatement[1024];
		int mods = 0, initcheck = 0;
		UCHAR key;

		GetPrivateProfileString(secName, TEXT("exec"), TEXT("console.write('Please type exec statement')"), execStatement, 1024, pluginIni.c_str());
		GetPrivateProfileString(secName, TEXT("name"), TEXT("(No name)"), funcName, 256, pluginIni.c_str());
		mods = GetPrivateProfileInt(secName, TEXT("modifiers"), 0, pluginIni.c_str());
		key = (UCHAR) GetPrivateProfileInt(secName, TEXT("key"), NULL, pluginIni.c_str());
		initcheck = GetPrivateProfileInt(secName, TEXT("init"), 0, pluginIni.c_str());

		// Buffer overflow
		if (i >= MAX_FUNCS)
			break;

		funcStatements.push_back(execStatement);
		addFunction(funcName, funcs[i], key, mods, initcheck);
		i++;
	}
	
}

// Read plugin ini
void readPluginIni()
{
	readPluginDetailsIni();
	readPluginFuncsIni();
}

// DLL Plugin is created
void pluginCreated()
{
	// Read plugin manifesto ini
	readPluginIni();

	// Add separator before About if other items available
	if (funcItems.size() > 0)
		addFunction(TEXT("\0"), NULL);

	// Minium of one function is required, hardcoded About as last is not a bad idea.
	addFunction(TEXT("About"), about);
}

// DLL Plugin is destroyed
void pluginDestroyed()
{

}


/* DLL Definitions are below */

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			// Get plugin directory from plugin DLL
			WCHAR pluginFilename[512];
			GetModuleFileName(hModule, pluginFilename, 512);
			pluginDirectory = wstring(pluginFilename);

			// Remove just the ".dll" from the filename, add .ini
			pluginDirectory = pluginDirectory.substr(0, pluginDirectory.length() - 4);
			pluginIni = pluginDirectory + TEXT(".ini");

			// Initialization
			pluginCreated();
			break;

		case DLL_PROCESS_DETACH:
			pluginDestroyed();
			break;

		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			break;
	}
	return TRUE;
}


extern "C" __declspec(dllexport) void setInfo(NppData npd)
{
	nppData = npd;
}

extern "C" __declspec(dllexport) const TCHAR * getName()
{
	return pluginName.c_str();
}

extern "C" __declspec(dllexport) FuncItem * getFuncsArray(int *funcItemCount)
{
	*funcItemCount = funcItems.size();
	return &funcItems[0]; // Vector assures similar array as C
}


extern "C" __declspec(dllexport) void beNotified(SCNotification *notifyCode)
{
	// Make sure the messages are from this plugin instances handle
	if (notifyCode->nmhdr.hwndFrom != nppData._nppHandle)
		return;

	// Handle messages
	switch(notifyCode->nmhdr.code)
	{
		case NPPN_READY:
			break;
	}
}


extern "C" __declspec(dllexport) LRESULT messageProc(UINT Message, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}

extern "C" __declspec(dllexport) BOOL isUnicode()
{
	return TRUE;
}