//============================================================================
// Name        : ATcoder.cpp
// Author      : Akari Fujii
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {

	int r,g,b;
	int u;
	cin>>r>>g>>b;

	r=r*100;
	g=g*10;

	u=r+g+b;

	if(u%4==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}


	return 0;
}
