#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
vector<int> G[N];
bool ans;

int dfs(int u, int p) {
	int cnt = 0;
	for (int v : G[u]) if (v != p) {
		int w = dfs(v, u); if (w == 0) ++cnt;
	}
	if (cnt <= 1) return cnt;
	else ans = true;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if (n == 2) return printf("Second\n"), 0;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}

	int res = dfs(1, 0);
	if (res == 0) ans = 1; 

	printf(ans ? "First\n" : "Second\n");
}