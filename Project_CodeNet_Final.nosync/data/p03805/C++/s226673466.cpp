#include<cstdio>

int g[8][8];
int dp[8][256];
int main()
{
  int n,m,u,v,s,k;scanf("%d%d",&n,&m);
  while(m--)scanf("%d%d",&u,&v),u--,v--,g[u][v]=g[v][u]=true;
  dp[0][1]=1,s=1<<n;
  for(k=1;k<s;k++)
	for(u=0;u<n;u++)
	  if(dp[u][k])
		for(v=0;v<n;v++)
		  if(g[u][v]&&~k&1<<v)
			dp[v][k|1<<v]+=dp[u][k];
  int ans=0;
  for(u=0;u<n;u++)ans+=dp[u][s-1];
  printf("%d\n",ans);
}