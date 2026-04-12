#include <iostream>
#include <string>
using namespace std;
const string s1="YES",s2="NO";
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int num=a*100+b*10+c;
	puts((num%4==0)?s1.c_str():s2.c_str());
	return 0;
}