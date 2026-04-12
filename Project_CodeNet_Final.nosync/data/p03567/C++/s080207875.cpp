#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<assert.h>
#include<algorithm>
//#include<iostream>
using namespace std;

char s[10];
int main()
{
	scanf("%s",s);int len=strlen(s);
	bool flag=0;
	for (int i=0;i<len-1;i++)
		if (s[i]=='A' && s[i+1]=='C') flag=1;
	puts(flag?"Yes":"No");
	return 0;
}