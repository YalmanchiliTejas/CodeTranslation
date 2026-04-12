#include<cstdio>
using namespace std;
bool mp[100][100];
bool dian[100];
int ans=0;
int m,n;
void dfs(int v,int dep)
{
	if(dep==m)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		if(mp[i][v]&&dian[i])
		{
			dian[v]=false;
			dfs(i,dep+1);
			dian[v]=true;
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		dian[i]=true;
	}
	for(int a,b,i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a][b]=true;
		mp[b][a]=true;
	}
	dfs(1,1);
	printf("%d",ans);
	return 0;
}