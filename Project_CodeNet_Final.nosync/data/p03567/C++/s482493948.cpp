#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[10];
int main()
{
	scanf("%s",s+1);int n=strlen(s+1);
	for(int i=1;i<n;i++)
		if(s[i]=='A'&&s[i+1]=='C')
			return !printf("Yes\n");
	return !printf("No\n");
}