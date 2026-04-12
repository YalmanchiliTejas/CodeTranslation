#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_N = 1e4 + 4, MAX_M = 1e2 + 2, MOD = 1e9 + 7;
string k;
int n, d;
int dp[2][MAX_N][MAX_M];

int _sum (int a, int b) {
	int c = a + b;
	if (MOD <= c)
		c -= MOD;
	
	return c;
}

int _mul (int a, int b) {
	int c = 1LL * a * b % MOD;
	return c;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> k >> d;
	k = '#' + k;
	dp[1][0][0] = 1;
	for (int i = 1; i < k.size(); i++)
		for (int j = 0; j < d; j++) {
			dp[1][i][j] = dp[1][i - 1][(j - (k[i] - '0') + d * 10) % d];
			for (int h = 0; h < (k[i] - '0'); h++)
				dp[0][i][j] = _sum(dp[0][i][j], dp[1][i - 1][(j - h + d * 10) % d]);

			for (int h = 0; h < 10; h++)
				dp[0][i][j] = _sum(dp[0][i][j], dp[0][i - 1][(j - h + d * 10) % d]);
		}

	cout << (_sum(dp[0][k.size() - 1][0], dp[1][k.size() - 1][0]) - 1 + MOD) % MOD;
	return 0;
}