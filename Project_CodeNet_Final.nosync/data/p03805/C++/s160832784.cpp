#include <iostream>
#include <vector>

using namespace std;

int dp[(1 << 8)+1][8];
int gragh[8][8];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		gragh[a - 1][b - 1]++;
		gragh[b - 1][a - 1]++;
	}

	dp[1][0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!((i >> k)&1) && gragh[j][k]>0) {
					dp[i + (1 << k)][k] += dp[i][j];
				}
			}
			if (i == (1 << n) - 1) {
				dp[1 << n][0] += dp[i][j];
			}
		}
	}

	cout << dp[1 << n][0] << endl;
}