#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << #var << " = " << var;
#else
#define debug(var)
#endif

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int n, m;
vector<int> g[10];
bool bio[10];

int dfs(int u=0, int cnt=1) {
	if (cnt == n) return 1;
	bio[u] = true;
	int ret = 0;
	for (int v: g[u]) {
		if (bio[v]) continue;
		ret += dfs(v, cnt+1);
	}
	bio[u] = false;
	return ret;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	printf("%d", dfs());
	
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
