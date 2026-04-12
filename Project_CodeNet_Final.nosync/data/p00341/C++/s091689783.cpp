//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int E;
int A[102]={};
int main() {
	for(int i=0;i<12;i++){
		cin>>E;
		A[E]+=1;
	}

	int R=0;
	for(int i=1;i<101;i++){
		if(A[i]==4)R+=1;
		if(A[i]==8)R+=2;
		if(A[i]==12)R=3;
	}

	if(R==3)cout<<"yes"<<endl;

	else cout<<"no"<<endl;

	return 0;
}