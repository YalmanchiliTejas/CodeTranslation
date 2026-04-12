#include <bits/stdc++.h>
#define N 200010
using namespace std;

int n, q[N], l, r, deg[N];
bool vis[N], inqueue[N];
vector<int> edge[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
		++deg[x]; ++deg[y];
	}
	
	l = r = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			q[++r] = i;
			inqueue[i] = 1;
		}
	}

	while (l < r) {
		int nq = -1;
		int u = q[l++];
		for (int j = 0; j < edge[u].size(); ++j) {
			int v = edge[u][j];
			if (!vis[v]) {
				nq = v;
				vis[v] = 1;
				vis[u] = 1;
				break;
			}
		}
		
		if (nq == -1) continue;
		for (int i = 0; i < edge[nq].size(); ++i) {
			int v = edge[nq][i];
			if (!inqueue[v] && --deg[v] == 1) {
				q[++r] = v;
				inqueue[v] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			puts("First");
			return 0;
		}
	}
	puts("Second");
}