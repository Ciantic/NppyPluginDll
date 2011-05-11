// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NPPYPLUGINDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NPPYPLUGINDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef NPPYPLUGINDLL_EXPORTS
#define NPPYPLUGINDLL_API __declspec(dllexport)
#else
#define NPPYPLUGINDLL_API __declspec(dllimport)
#endif

// This class is exported from the NppyPluginDll.dll
class NPPYPLUGINDLL_API CNppyPluginDll {
public:
	CNppyPluginDll(void);
	// TODO: add your methods here.
};

extern NPPYPLUGINDLL_API int nNppyPluginDll;

NPPYPLUGINDLL_API int fnNppyPluginDll(void);
