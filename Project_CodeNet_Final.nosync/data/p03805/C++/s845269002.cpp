#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> e(n, vector<bool>(n));
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		e[u][v] = true;
		e[v][u] = true;
	}
	int res = 0;
	vector<int> p(n - 1);
	iota(p.begin(), p.end(), 1);
	do {
		int last = 0;
		bool g = true;
		for (int x : p) {
			if (!e[last][x]) {
				g = false;
				break;
			}
			last = x;
		}
		if (g) {
			res++;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << res << '\n';

	return 0;
}

