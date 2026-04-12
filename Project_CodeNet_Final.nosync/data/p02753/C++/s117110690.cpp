#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
	string S;
	cin >> S;
	
	if(S.find("A")!=std::string::npos&&S.find("B")!=std::string::npos) {

		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

}