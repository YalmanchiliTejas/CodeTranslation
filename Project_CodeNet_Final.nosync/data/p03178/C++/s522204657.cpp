#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 105;
const int mod = 1e9 + 7;
int n, num[N], d;
string snum;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

/* TOP DOWN 
int mem[N][M][2];
bool vis[N][M][2];

int dp(int i, int m, bool border) {
	if (i == n) {
		return m ? 0 : 1;
	}
	if (vis[i][m][border]) {
		return mem[i][m][border];
	}
	vis[i][m][border] = true;

	int lv = border ? num[i] : 9;

	int ans = 0;
	for (int j = 0; j <= lv; j++) {
		bool nb = border && j == lv;
		ans = add(ans, dp(i + 1, (m + j) % d, nb));
	}

	return mem[i][m][border] = ans;
}
*/

int dp[N][M][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> snum >> d;
	n = snum.size();

	for (int i = 0; i < n; i++) {
		num[i] = snum[i] - '0';
	}

	dp[n][0][1] = 1;
	dp[n][0][0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int m = 0; m < d; m++) {
			for (int border = 0; border < 2; border++) {
				int lv = border ? num[i] : 9;

				for (int j = 0; j <= lv; j++) {
					int nb = border && (j == lv);
					dp[i][m][border] = add(dp[i][m][border], dp[i + 1][(m + j) % d][nb]);
				}
			}
		}
	}

	cout << (mod + dp[0][0][1] - 1) % mod << '\n';

	return 0;
}
