#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

struct Edge {
	int v, x;
} E[maxn << 1];

int l[maxn], n, dep[maxn], fa[maxn], vis[maxn], ok = 1, e;

struct CMP {
	bool operator()(const int &a, const int &b) const {
		if (dep[a] == dep[b]) return a < b;
		return dep[a] > dep[b];
	}
};

set<int, CMP> st;

inline void addEdge(int u, int v) {
	E[e].v = v; E[e].x = l[u]; l[u] = e++;
}

void dfs(int u, int f) {
	fa[u] = f;
	for (int p = l[u]; p >= 0; p = E[p].x) {
		int v = E[p].v;
		if (v != f) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}

int main() {
	memset(l, -1, sizeof(l));
	scanf("%d", &n);
	if (n & 1) {
		puts("First");
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) st.insert(i);
	while (!st.empty()) {
		int u = *(st.begin());
		if (vis[fa[u]]) {
			ok = 0;
			break;
		}
		vis[fa[u]] = vis[u] = 1;
		st.erase(fa[u]);
		st.erase(u);
	}
	if (!ok) puts("First");
	else puts("Second");
	return 0;
}