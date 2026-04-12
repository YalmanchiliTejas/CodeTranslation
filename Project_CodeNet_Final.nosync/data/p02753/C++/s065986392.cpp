#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<stack>
using namespace std;
char s[10];
int ci1,ci2;
int main()
{
	scanf("%s",s+1);
	for(int i=1;i<=3;i++)
	{
		if(s[i]=='A')
		{
			ci1++;
		} 
		if(s[i]=='B')
		{
			ci2++;
		}
	}
	if(ci1&&ci2)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}