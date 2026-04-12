#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int cnt[N];
vector<int> adj[N];
bool ok = true;

void dfs(int v, int p)
{
	int bad = 0;
	cnt[v] = 1;
	for (auto u : adj[v])
	{
		if (u == p)
			continue;
		dfs(u, v);
		cnt[v] += cnt[u];
		if (cnt[u] % 2 == 1)
			bad++;
	}
	if (bad > 1)
		ok = false;
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i=1; i<n; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	dfs(0, -1);
	if (!ok || cnt[0] % 2 == 1)
		cout << "First\n";
	else
		cout << "Second\n";

	return 0;
}