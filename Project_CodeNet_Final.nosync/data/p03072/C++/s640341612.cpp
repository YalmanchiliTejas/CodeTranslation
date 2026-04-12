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
#include <stdio.h>
using namespace std;
typedef long long ll;
int main() {
	int N;
	int H[101];
	int A[101]={};
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>H[i];
		A[i]=0;
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			if(H[i]<H[j]){
				A[i]=1;
				break;
			}
		}
	}
	int R=N;
	for(int i=0;i<N;i++){
		if(A[i]==1)R--;
	}
	cout<<R<<endl;
	return 0;
}
