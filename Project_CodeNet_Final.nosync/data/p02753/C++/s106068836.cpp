#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool flag=false,flag2=false;
char s[10];
int main(void)
{	
	scanf("%s",s);
	if(strlen(s)!=3)
	{
		printf("No\n");
		return 0;
	}
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')
			flag=true;
		if(s[i]=='B')
			flag2=true;
	}
	if(flag==true&&flag2==true)
	{
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
    return 0;
}