//============================================================================
// Name        : AOJ.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[300001]={};

int main() {
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>d[i];
	}
	int d1=0;
	int flg=0;
	for(int i=0;i<n;++i){
		d1=max(d1,10*i+d[i]);
		if(d1<10*(i+1))flg=1;
	}
	d1=10*(n-1);
	for(int i=n-1;i>=0;--i){
		d1=min(d1,10*i-d[i]);
		if(d1>10*(i-1))flg=1;
	}

	if(flg==0){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
		return 0;
}