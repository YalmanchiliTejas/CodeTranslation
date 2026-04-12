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
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
string S;
int n;
int main(){
	cin>>n;

	int B[27];
	for(int i=0;i<27;i++){
		B[i]=100;
	}
	for(int i=0;i<n;i++){
		cin>>S;
		int A[27]={};
		int L=S.size();
		for(int j=0;j<L;j++){
			int C=S[j]-97;
			A[C]++;
		}
		for(int j=0;j<27;j++){
			B[j]=min(A[j],B[j]);

		}
	}

	for(int i=0;i<27;i++){
		int k=i+97;
		char chr=k;
		for(int j=0;j<B[i];j++){
			cout<<chr;
		}
	}

	cout<<endl;

    return 0;
}
