#include "bits/stdc++.h"
using namespace std;
char str[101][101];
int main()
{
	int n,m,sum=0;
	int i,j,flag;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);
	}
	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=0;j<m;j++)
		{
			if(str[i][j]=='#')
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			for(j=0;j<m;j++)
			{
				str[i][j]='G';
			}
		}
	}
	for(j=0;j<m;j++)
	{
		flag=1;
		for(i=0;i<n;i++)
		{
			if(str[i][j]=='#')
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			for(i=0;i<n;i++)
			{
				str[i][j]='G';
			}
		}
	}
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<m;j++)
		{
			if(str[i][j]=='G')
			{
				continue;
			}
			printf("%c",str[i][j]);
			sum++;
		}
		if(sum)
		{
			printf("\n");
		}
	}
	return 0;
}