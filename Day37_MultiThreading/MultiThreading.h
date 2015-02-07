#include <process.h>
#include <Windows.h>

class MultiThreading{
	int len;
	const char threadNum;	
	unsigned int *threadID;
	void *argList;
	HANDLE *hThread;
	
	//HANDLE g_hThreadSemaphore;
	//CRITICAL_SECTION g_csThread;
	unsigned int  (WINAPI *pThreadFunc)(void*);
public:
	MultiThreading(unsigned int  (WINAPI *)(void*),char,void*);
	HANDLE* createThreading();
	void closeThreading();
};