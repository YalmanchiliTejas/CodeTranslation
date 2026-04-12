#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
int main()
{
	cin>>str;
	if(str.find("AC")!=str.npos)printf("Yes\n");
	else printf("No\n");
	return 0;
}