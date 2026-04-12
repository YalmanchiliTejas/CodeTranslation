#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int MXN = 8;

int n, m;
vector<bool> vis(MXN);
vector<int> adj[MXN];

ll dfs(int cur) {
	ll ans = 0;
	vis[cur] = true;
	bool all = true;
	for (int i=0; i<n && all; i++)
		if (!vis[i]) all = false;
	if (all) {
		vis[cur] = false;
		return 1;
	}
	for (int x : adj[cur])
		if (!vis[x]) ans += dfs(x);
	vis[cur] = false;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << dfs(0);
}