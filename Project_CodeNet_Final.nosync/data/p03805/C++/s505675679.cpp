#include <bits/stdc++.h>

using namespace std;

const int N = 15;

vector <int> g[N];
int n;

int dfs(int u, int mask) {
	if ((1 << n) - 1 == mask) return 1;
	int ans = 0;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if (!(mask & (1 << v))) {
			mask |= (1 << v);
			ans += dfs(v, mask);
			mask &= ~(1 << v);                      
		}
	}
	return ans;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	int ans = dfs(0, 1);
	printf("%d\n", ans); 
	return 0;
}