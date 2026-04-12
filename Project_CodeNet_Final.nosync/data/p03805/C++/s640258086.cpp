#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

vector<int> graph[10];
vector<bool> visit(10, false);
int n, cnt = 0;

bool check(void)
{
	rep(i, n)
	{
		if (!visit[i])
			return false;
	}
	return true; 
}

void dfs(int v, int p = -1)
{
	if (check()) 
	{
		cnt++;
		return;
	}
	for(int i = 0; i < graph[v].size(); i++)
	{
		if (graph[v][i] == p) continue;
		if (visit[graph[v][i]]) continue;
		visit[graph[v][i]] = true;
		dfs(graph[v][i], v);
		visit[graph[v][i]] = false;
	}
}

signed main(void)
{
	int m; 
	cin >> n >> m;
	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	visit[0] = true;
	dfs(0);
	cout << cnt << endl;
	return 0;
}
