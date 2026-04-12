#include <bits/stdc++.h>
using namespace std;

int n, m, rv = 0;

vector<int> g[8];
void dfs(int v, int bit) {
	if (bit == (1 << n) - 1) {
		rv++;
		return;
	}
	for (int nv : g[v]) {
		if (bit & (1 << nv))
			continue;
		dfs(nv, bit | (1 << nv));
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b, a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, 1);
	cout << rv << endl;

}
