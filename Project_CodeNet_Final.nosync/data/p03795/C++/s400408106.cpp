//============================================================================
// Name        : AOJ.cpp
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
int main(){


	int n;
	int m;
	int o;

	cin>>n;

	m=800*n;

	if(n>=15){
		o=n/15;
	}
	o=o*200;

	cout<<m-o<<endl;

	return 0;



}
