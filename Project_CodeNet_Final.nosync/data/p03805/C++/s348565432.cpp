#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool adj[8][8];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u][v] = true;
		adj[v][u] = true;
	}

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	int ans = 0;
	do {
		if (p[0] != 0) continue;
		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			if (!adj[p[i]][p[i + 1]]) {
				ok = false;
			}
		}
		if (ok) {
			ans++;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << endl;
    return 0;
}