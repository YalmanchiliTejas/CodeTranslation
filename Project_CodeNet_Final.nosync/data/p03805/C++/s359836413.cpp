#include<cstdio>
#include<vector>
using namespace std;
vector<int>x[10];
bool vis[10];
int n,m,ans=0;
void dfs(int v)
{
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			flag=false;
		}
	}
	if(flag)
	{
		ans++;
		return;
	}
	for(int i=x[v].size()-1;i>=0;i--)
	{
		if(!vis[x[v][i]])
		{
			vis[x[v][i]]=1;
			dfs(x[v][i]);
			vis[x[v][i]]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		x[a].push_back(b);
		x[b].push_back(a);
	}
	vis[1]=1;
	dfs(1);
	printf("%d",ans);
	return 0;
}