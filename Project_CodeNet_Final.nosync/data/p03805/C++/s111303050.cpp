#include <bits/stdc++.h>

using namespace std;

typedef vector< vector<int> > Graph;

int n, m;
bool g[10][10];

int dp[260][10];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a][b] = true;
		g[b][a] = true;
	}	

	dp[1][0] = 1;
	for (int i = 1; i < (1 << n) - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) continue;
			for (int k = 0; k < n; k++) {
				if (i & (1 << k)) {
					if (!g[j][k]) continue;
					dp[i | (1 << j)][j] += dp[i][k];
				}
			}
		}
	}

	int ans = 0;
	int s = (1 << n) - 1;
	for (int i = 1; i < n; i++) {
		ans += dp[s][i];
	}
	cout << ans << endl;
	return 0;
}