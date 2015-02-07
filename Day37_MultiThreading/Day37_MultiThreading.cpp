// Day37_MultiThreading.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MultiThreading.h"

CRITICAL_SECTION h_csThread;
char i=0;
unsigned int WINAPI threadFunc(void *pPM){
	//int arg=*(int*)pPM;
	EnterCriticalSection(&h_csThread);
	printf("%d Hello World\n",++i);
	LeaveCriticalSection(&h_csThread);
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	InitializeCriticalSection(&h_csThread);
	const char num=3;
	int i=10;
	MultiThreading hThread(threadFunc,num,&i);
	hThread.createThreading();
	
	hThread.closeThreading();	
	//while(1);
	return 0;
}

