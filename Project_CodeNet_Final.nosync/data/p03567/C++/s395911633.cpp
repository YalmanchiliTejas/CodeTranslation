#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	if(str.find("AC")!=string::npos) printf("Yes\n");
	else printf("No\n");
	return 0;
}