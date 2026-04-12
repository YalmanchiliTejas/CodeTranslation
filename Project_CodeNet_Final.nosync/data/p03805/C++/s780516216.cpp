#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int map[10][10];
int vis[10];
int n,m,sum;
void dfs(int x,int num)
{
	if(num==n)
	{
		sum++;
		return;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&map[x][i]==1)
		{
			vis[i]=1;
			map[x][i]=0;
			dfs(i,num+1);
			vis[i]=0;
			map[x][i]=1;
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			map[a][b]=1;
			map[b][a]=1;
		}
		sum=0;
		dfs(1,1);
		printf("%d\n",sum);
	}
	return 0;
}