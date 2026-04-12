#include<bits/stdc++.h>
using namespace std;
int n,m;
char f[101][101]={0};
int check(int a,int i)
{
	int j;
	if(a==0)
	{
		for(j=0;j<m;j++)
		{
			if(f[i][j]=='#')
				return 0;
		}
		return 1;
	}
	else
	{
		for(j=0;j<n;j++)
		{
			if(f[j][i]=='#')
				return 0;
		}
		return 1;
	}
}
void remove(int a,int i)
{
	int j;
	if(a==0)
	{
		for(j=0;j<m;j++)
		{
			f[i][j]=' ';
		}
	}
	else
	{
		for(j=0;j<n;j++)
		{
			f[j][i]=' ';
		}
	}
}
int main()
{
	int i,j,t;
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%s",f[i]);
	}
	for(i=0;i<n;i++)
	{
		if(check(0,i))
			remove(0,i);
	}
	for(j=0;j<m;j++)
	{
		if(check(1,j))
			remove(1,j);
	}
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;j<m;j++)
		{
			if(f[i][j]!=' ')
			{
				printf("%c",f[i][j]);
				t=1;
			}
		}
		if(t)
			printf("\n");
	}
	return 0;
}