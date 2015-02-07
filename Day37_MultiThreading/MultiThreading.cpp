#include "stdafx.h"
#include "MultiThreading.h"


MultiThreading::MultiThreading(unsigned int(WINAPI *pFunc)(void* pPm),char num,void *arg):pThreadFunc(pFunc),threadNum(num),argList(arg){
	/*pThreadFunc=pFunc;
	threadNum=num*/
	hThread=new HANDLE[threadNum];
	threadID=new unsigned int[threadNum];
}

HANDLE* MultiThreading::createThreading(){
	for(int i=0;i<threadNum;i++){
		hThread[i]=(HANDLE)_beginthreadex(NULL,0,pThreadFunc,argList,0,&threadID[i]);
	}
	WaitForMultipleObjects(threadNum,hThread,true,INFINITE);
	
	return hThread;
}

void MultiThreading::closeThreading(){
	for(int i=0;i<threadNum;i++){
		CloseHandle(hThread[i]);
	}
}