#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n;
int f[N], g[N];
vector<int> G[N];

void dfs(int p, int fa) {
	f[p] = 1, g[p] = 0;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p);
			f[p] += g[e];
			g[p] += max(f[e], g[e]);
		}
	}
}

int main() {
	scanf("%d", &n);;
	if (n & 1) {
		puts("First");
		return 0;
	}
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	puts((max(f[1], g[1]) == (n >> 1)) ? ("Second") : ("First"));
	return 0;
}
