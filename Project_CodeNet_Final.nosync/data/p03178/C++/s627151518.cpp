#include <iostream>
using namespace std;

const int N = 1e4 + 4, D = 1e2 + 2, MOD = 1e9 + 7;

string k;
int d, n;
int dp[N][D][2];
// dp[i][j][0] : < k
// dp[i][j][1] : = k

int _sum(int a, int b) {
	int c = a + b;
	if (MOD <= c)
		c -= MOD;

	return c;
}

int _sub(int a, int b) {
	int c = a - b;
	if (c < 0)
		c += MOD;

	return c;
}

int _mul(int a, int b) {
	return 1LL * a * b % MOD;
}


int main() {
	cin >> k >> d;
	n = k.size();
	k = '0' + k;

	dp[0][0][1] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < d; j++) {
			int h = k[i] - '0';

			for (int p = 0; p < h; p++)
				dp[i][j][0] = _sum(dp[i][j][0], dp[i - 1][(j - p + 10 * d) % d][1]);
			for (int p = 0; p < 10; p++)
				dp[i][j][0] = _sum(dp[i][j][0], dp[i - 1][(j - p + 10 * d) % d][0]);

			dp[i][j][1] = dp[i - 1][(j - h + 10 * d) % d][1];
		}

	cout << _sub(_sum(dp[n][0][0], dp[n][0][1]), 1) << "\n";
}