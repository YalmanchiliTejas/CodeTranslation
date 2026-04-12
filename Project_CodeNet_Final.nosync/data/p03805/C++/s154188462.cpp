#include<cstdio>
#include<vector>
using namespace std;
vector<int> edge[10];
bool vis[10] = {false};
int ans = 0;
int n, m, a, b;

void dfs(int t, int d)
{
	if(d == n)	
	{
		ans++;
		return;
	}
	for(int i = edge[t].size() - 1; i >= 0; --i)
	{
		int now = edge[t][i];
		if(vis[now] == false)
		{
			vis[now] = true;
			dfs(now, d + 1);
			vis[now] = false;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a ,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);	
	}
	vis[1] = true;
	dfs(1, 1);
	printf("%d", ans);
	return 0;
}