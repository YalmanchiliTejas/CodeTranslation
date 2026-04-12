/* به نام یزدان */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10 * 1000 + 3, MAX_D = 100 + 3, MOD = 1e9 + 7;
int n, d, a[MAX_N], dp[MAX_N][MAX_D][2];

void read_input() {
	string k;
	cin >> k >> d;
	n = k.size();
	for (int i = 1; i <= n; i++)
		a[i] = k[n - i] - '0';
}

int get(int w, int x) {
	return ((w - x) % d + d) % d;
}

void solve() {
	dp[0][0][0] = dp[0][0][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < d; j++) {
			for (int k = 0; k < 10; k++)
				(dp[i][j][1] += dp[i - 1][get(j, k)][1]) %= MOD;
			for (int k = 0; k < a[i]; k++)
				(dp[i][j][0] += dp[i - 1][get(j, k)][1]) %= MOD;
			(dp[i][j][0] += dp[i - 1][get(j, a[i])][0]) %= MOD;
		}
}

void print_output() {
	cout << ((dp[n][0][0] - 1) % MOD + MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	read_input();
	solve();
	print_output();
}
