#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
char s[10][10];
int main()
{
	int h,w,now=1;
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
			if(s[i][j]=='#')
			{
				if(j==now+1)
					now++;
				else if(now!=j)
				{
					printf("Impossible");
					return 0;
				}
			}
	}
	printf("Possible");
	return 0;
}