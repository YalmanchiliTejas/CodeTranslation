#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
int ans = 0;
void dfs(int n, Graph &G, vector<bool> &visited ,int v) {
	int i;
	bool flag = true;
	for (i = 0; i < n; i++) {
		if (!visited[i] && i != v) flag = false;
	}
	if (flag) {
		ans++;
		return;
	}
	visited[v] = true;
	for (auto c : G[v]) {
		if (visited[c]) continue;
		dfs(n, G, visited, c);
	}
	visited[v] = false;
}
int main() {
	int n, m;
	cin >> n >> m;
	int i;
	Graph G(n, V(n, 0));
	for (i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<bool> visited(n, false);
	dfs(n, G , visited, 0);
	cout << ans;
	return 0;
}