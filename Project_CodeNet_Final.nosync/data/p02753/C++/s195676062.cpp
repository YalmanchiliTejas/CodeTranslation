#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char s[4];
	for (int i = 0; i < 3;i++)
	{
		scanf("%c",&s[i]);
	}
	int flag = 0;
	for (int i = 0; i < 2;i++)
	{
		if(s[i]!=s[i+1])
		{
				flag = 1;
				break;
		}
	}
	if(flag==0)
		printf("No\n");
	else
		printf("Yes\n");
}
