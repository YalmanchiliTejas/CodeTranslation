#include<cstdio>
#include<vector>
using namespace std;
int n;
int a,b;
vector<int>g[100001];
bool f[100001];
bool dfs(int x,int fa)
{
	f[x]=1;
	int cnt=0;
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]==fa)continue;
		if(dfs(g[x][i],x))return 1;
		if(f[g[x][i]])
		{
			cnt++;
			f[x]=0;
			if(cnt==2)return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(dfs(1,0)||f[1])printf("First");
	else printf("Second");
}