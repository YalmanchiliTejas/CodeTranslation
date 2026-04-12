#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	char s[8];
	int i,flag=1;
	scanf("%s",s);
	for(i=0;i<strlen(s)-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		{
			cout<<"Yes"<<endl; 
			flag=0;
			break;
		}
	}
	if(flag) cout<<"No"<<endl; 
}