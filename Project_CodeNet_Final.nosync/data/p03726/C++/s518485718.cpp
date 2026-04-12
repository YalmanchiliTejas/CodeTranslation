#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int n;
vector<int>w[MAXN];
queue<int>Q;
int rd[MAXN];
bool vis[MAXN];
int main()
{
	//freopen("blackwhite.in","r",stdin);
	//freopen("blackwhite.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		w[u].push_back(v);
		w[v].push_back(u);
		rd[u]++;
		rd[v]++;
	}
	for(int i=1;i<=n;i++)
		if(rd[i]==1)
			Q.push(i);
	while(!Q.empty())
	{
		int k=Q.front();
		Q.pop();
		if(rd[k]!=1||vis[k])
			continue;
		int u=0;
		for(int i=0;i<int(w[k].size());i++)
		{
			int v=w[k][i];
			if(!vis[v])
			{
				u=v;
				break;
			}
		}
		vis[k]=vis[u]=1;
		for(int i=0;i<int(w[u].size());i++)
		{
			int v=w[u][i];
			rd[v]--;
			if(rd[v]==1)
			{
				Q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			printf("First\n");
			return 0;
		}
	}
	printf("Second\n");
	fclose(stdin);
	fclose(stdout);
}