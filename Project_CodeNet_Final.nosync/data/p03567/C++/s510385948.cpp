#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[10];
	int len;
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<len;i++)
		if(s[i]=='A'&&s[i+1]=='C') {puts("Yes");return 0;}
	puts("No");	
	return 0;
}