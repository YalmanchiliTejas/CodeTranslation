#include<bits/stdc++.h>
using namespace std;
char a[100][100];
bool zlm[100][100];
int length,width,cnt;
bool ok=false;
void dfs(int x,int y)
{
	if(x==width&&y==length)
	{
		ok=true;
	}
	if(a[x][y+1]=='#')
	{
		if(zlm[x][y+1]==0)
		{
			cnt++;
			zlm[x][y+1]=1;
			dfs(x,y+1);
			return;
		}
	}
	if(a[x+1][y]=='#')
	{
		if(zlm[x+1][y]==0)
		{
			cnt++;
			zlm[x+1][y]=1;
			dfs(x+1,y);
			return;
		}	
	}
}
int main()
{
	scanf("%d%d",&width,&length);
	for(int i=1;i<=width;i++)
	{
		scanf("%s",a[i]+1);
	}
	for(int i=1;i<=width;i++)
	{
		for(int j=1;j<=length;j++)
		{
			if(a[i][j]=='#')
			{
				cnt--;
			}
		}
	}
	cnt++;
	dfs(1,1);
	if(ok==true&&cnt==0)
	{
		printf("Possible");
	}
	else
	{
		printf("Impossible");
	}
	return 0;
}