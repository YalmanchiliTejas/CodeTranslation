#include <bits/stdc++.h>
using namespace std;
vector<int> a[10];
int n, m, ans;
int vis[10];

void dfs(int x, int t)
{
	if(t == n) {ans ++; return;}
	for(int i = 0; i < a[x].size(); i ++)
	{
		int y = a[x][i];
		if(vis[y]) continue;
		vis[y] = 1;
		dfs(y, t + 1);
		vis[y] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vis[1] = 1;
	dfs(1, 1);
	cout << ans;
	return 0;
}
