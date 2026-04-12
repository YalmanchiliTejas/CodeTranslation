#include <bits/stdc++.h>

const int kN = 1e5 + 5;

int n, siz[kN], fa[kN]; std::vector <int> E[kN];
void Add(int u, int v) { E[u].push_back(v); }
void Dfs(int u) {
	int cnt = 0; siz[u] = 1;
	for(auto v : E[u]) if(v != fa[u]) {
		fa[v] = u; Dfs(v);
		siz[u] ^= siz[v];
		if(siz[v]) ++cnt;
	}
	if(siz[u]) ++cnt;
//	printf("%d %d\n", u, cnt);
	if(cnt >= 2) {
		printf("First\n");
		exit(0);
	}
}

int main() {
	scanf("%d", &n);
	if(n & 1) {
		printf("First\n");
		return 0;
	}
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		Add(u, v); Add(v, u);
	}
	Dfs(1);
	printf("Second\n");
	return 0;
}