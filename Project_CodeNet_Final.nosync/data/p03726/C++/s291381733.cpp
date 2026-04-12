//In the name of GOD
//SMani24
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

int n;
bool dp1[N], dp0[N], mark[N];
vector <int> adj[N];

void dfs(int v) {
	mark[v] = true;
	bool b = false;
	int c = 0, cl = 0;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
			cl++;
			if (dp0[u])
				c++;
			if (dp1[u])
				b = true;
		}
	}
	if (c == cl)
		dp1[v] = true;
	if (c + 1 == cl && b)
		dp0[v] = true;
}

void read_input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
}
void solve() {
	dfs(0);
}
void write_output() {
	if (dp0[0])
		cout << "Second";
	else
		cout << "First";
}

int32_t main() {
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve(), write_output();
	return 0;
}
