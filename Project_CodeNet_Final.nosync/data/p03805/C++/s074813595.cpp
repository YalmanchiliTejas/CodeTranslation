#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n));
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = 1;
	}
	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 0);
	int ans = 0;
	do {
		bool ok = true;
		for(int i = 0; i < n - 1; i++) {
			if(!g[perm[i]][perm[i + 1]]) ok = false;
		}
		ans += ok;
	} while(next_permutation(perm.begin() + 1, perm.end()));
	cout << ans << endl;
	return 0;	
}