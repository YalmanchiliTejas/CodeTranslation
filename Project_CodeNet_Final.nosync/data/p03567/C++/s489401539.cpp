#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[100001];
int main()
{
	scanf("%s",s+1);
	for(int i=1;i<strlen(s+1);i++)
	{
		if(s[i]=='A'&&s[i+1]=='C') 
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
} 