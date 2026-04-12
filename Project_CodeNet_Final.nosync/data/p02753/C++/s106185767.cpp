//============================================================================
// Name        : a.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

int main() {
	string s;cin>>s;
	int ans=0;
	if(s[0]=='A'){
		if(s[1]=='B'||s[2]=='B'){
			ans=1;
		}
	}else{
		if(s[1]=='A'||s[2]=='A'){
			ans=1;
		}
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
