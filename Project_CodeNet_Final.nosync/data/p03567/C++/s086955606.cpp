#include<cstdio>
#include<iostream>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s.find("AC")!=string::npos) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}