//============================================================================
// Name        : JOI.cpp
// Author      : 
// Version     : 20min
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	string str;
	cin>>str;
	int flg=0;
	for(int i=0;i<str.size()-1;++i){
		if(str[i]=='A'&&str[i+1]=='C')flg=1;
	}

	if(flg==0){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;

	}
	return 0;

}
