#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;
int dot,line,a,b;
int ans=0;
bool vis[10];
vector <int> to[10];
bool check()
{
	for(int i=1;i<=dot;i++)
	if(!vis[i])return false;
	return true;
}
void dfs(int now)
{
	vis[now]=true;
	if(check())
	{
		ans++;
		return;
	}
	for(int i=to[now].size()-1;i>=0;i--)
	{
		if(!vis[to[now][i]])
		{
			dfs(to[now][i]);
			vis[to[now][i]]=false;
		}
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	scanf("%d%d",&dot,&line);
	for(int i=1;i<=line;i++)
	{
		scanf("%d%d",&a,&b);
		to[a].push_back(b);
		to[b].push_back(a);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}