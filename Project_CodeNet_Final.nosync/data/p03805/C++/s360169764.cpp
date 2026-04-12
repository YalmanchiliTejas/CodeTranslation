#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
int ans = 0;
void dfs(int cur, vector<int> &vis) {
	bool flag = true;
	vector<int> v = vis;
	for(int i = 0; i < n; i++) {
		if(!vis[i]) flag = false;
	}
	if(flag) {
		ans++;
		return;
	}
	for(int i = 0; i < g[cur].size(); i++) {
		int nxt = g[cur][i];
		if(vis[nxt]) continue;
		v[nxt] = true;
		dfs(nxt, v);
		v[nxt] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	vector<int> vis(n, 0);
	vis[0] = 1;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, vis);
	cout << ans << endl;
	return 0;	
}
