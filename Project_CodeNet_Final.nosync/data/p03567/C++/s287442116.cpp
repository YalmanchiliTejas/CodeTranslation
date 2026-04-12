//============================================================================
// Name        : JOI.cpp
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

	string str;
	int d=0;
	cin>>str;


	for(int i=0; i<str.size();++i){
		if(str[i]=='A'&&str[i+1]=='C'){
			d+=1;
		}
	}
		if(d>0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}








}
