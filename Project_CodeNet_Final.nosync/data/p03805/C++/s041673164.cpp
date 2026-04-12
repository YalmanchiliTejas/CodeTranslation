#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, 0));
	while(m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = true;
	}
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	int ans = 0;
	do {
		bool can = true;
		for(int i = 0; i < a.size() - 1; i++) {
				if(!g[a[i]][a[i + 1]]) can = false;
		}
		if(can) ans++;
	} while(next_permutation(a.begin() + 1, a.end()));
	cout << ans << endl;
	return 0;	
}
