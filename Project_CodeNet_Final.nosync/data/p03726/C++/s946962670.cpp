#include<cstdio>
#define MAXN 100006
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> road[MAXN];
int n,u,v,du[MAXN],vis[MAXN];
queue<int> q;
int main()
{
	//freopen("blackwhite.in","r",stdin);
	//freopen("blackwhite.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		road[u].push_back(v);
		road[v].push_back(u);
		du[u]++;
		du[v]++;
	}
	for(int i=1;i<=n;i++)
		if(du[i]==1) q.push(i);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(vis[now]) continue;
		if(du[now]==1)
		{
			for(int i=0;i<(int)road[now].size();i++)
			{
				int nex=road[now][i];
				if(!vis[nex])
				{
					vis[nex]=vis[now]=1;
					for(int j=0;j<(int)road[nex].size();j++)
					{
						int nnex=road[nex][j];
						if(vis[nnex]) continue;
						du[nnex]--;
						if(du[nnex]==1) q.push(nnex);
					}
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			printf("First");
			return 0;
		}
	printf("Second");
}