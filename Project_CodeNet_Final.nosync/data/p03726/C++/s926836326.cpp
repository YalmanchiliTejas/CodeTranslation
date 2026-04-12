/*
As you do not know the path of the wind,
or how the body is formed in a mother's womb,
so you cannot understand the work of God,
the Maker of all things.
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int N = (int)1e5+5;
int n, col[N];
vector<int> g[N];

void dfs(int u, int p) {
	for (int v : g[u]) if (v != p)
		dfs(v, u);
	if (!col[u]) {
		if (u == 1 || (p && col[p])) {
			puts("First");
			exit(0);
		}
		col[u] = 1, col[p] = 2;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	puts("Second");
	return 0;
}
