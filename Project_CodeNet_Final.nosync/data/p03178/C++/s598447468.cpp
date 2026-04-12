#include <iostream>
#include <string>

using namespace std;

#define MOD 1000000007

long long dp[10002][100][2] = {};

int main() {
	string K; cin >> K;
	int D; cin >> D;
	int sz = K.size();
	dp[0][0][0] = 1;
	for (int i = 0; i < sz; ++i) {
		int c = K[i] - '0';
		for (int j = 0; j < D; ++j)
			for (int smaller = 0; smaller < 2; ++smaller)
				for (int k = 0; k < 10; ++k)
					if (k < c) (dp[i + 1][(j + k) % D][1] += dp[i][j][smaller]) %= MOD;
					else if (k == c) (dp[i + 1][(j + k) % D][smaller] += dp[i][j][smaller]) %= MOD;
					else if (smaller) (dp[i + 1][(j + k) % D][1] += dp[i][j][1]) %= MOD;
	}
	cout << (dp[sz][0][0] + dp[sz][0][1] - 1 + MOD) % MOD << endl;

	return 0;
}
