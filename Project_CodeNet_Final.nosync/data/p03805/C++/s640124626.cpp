#include<stdio.h>
#include<string.h>
int vis[20],map[20][20],n,m,sum;
void dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	if(vis[i]!=1)
	break;
	if(i==n+1)
	{
		sum++;
		return;
	}
	for(i=1;i<=n;i++)
	if(map[x][i]==1&&vis[i]==0)
	{
		vis[i]=1;
		dfs(i);
		vis[i]=0;
	}
	return ;
}
int main()
{
	int i,j,x,y;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=1;
			map[y][x]=1;
		}
		vis[1]=1;
		sum=0;
		for(i=2;i<=n;i++)
		{
			if(map[1][i]==1)
			{
			vis[i]=1;
			dfs(i);
			vis[i]=0;
		}
		}
		printf("%d\n",sum);
	}
	return 0;
}