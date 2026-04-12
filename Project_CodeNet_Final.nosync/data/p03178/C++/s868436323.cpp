#include <iostream>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
ll dp[10005][105][2];

int main(int argc, char *argv[])
{
	string K;
	ll D;

	cin >> K >> D;
	int n = K.length();

	dp[0][0][0] = 1;
	for (int dgt = 0; dgt < n; dgt++) {
		for (int d = 0; d < D; d++) {
			for (int smaller = 0; smaller < 2; smaller++) {
				int c = K[dgt] - '0';
				for (int next = 0; next < 10; next++) {
					if (next < c) {
						dp[dgt + 1][(d + next) % D][1] += dp[dgt][d][smaller];
						dp[dgt + 1][(d + next) % D][1] %= mod;
					} else if (next == c) {
						dp[dgt + 1][(d + next) % D][smaller] += dp[dgt][d][smaller];
						dp[dgt + 1][(d + next) % D][smaller] %= mod;
					} else {
						if (smaller) {
							dp[dgt + 1][(d + next) % D][smaller] += dp[dgt][d][smaller];
							dp[dgt + 1][(d + next) % D][smaller] %= mod;
						}
					}
				}
			}
		}
	}

	cout << (mod + ((dp[n][0][0] + dp[n][0][1]) % mod - 1)) % mod << endl;

	return 0;
}