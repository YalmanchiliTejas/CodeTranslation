#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[10001][101];
int main() {
	string K; int D; cin >> K >> D;
	reverse(K.begin(), K.end());
	for (int i = 0; i <= 9; i++) dp[0][i % D] += 1;
	for (int i = 1; i < K.size(); i++) {
		for (int j = 0; j < D; j++) {
			for (int k = 0; k <= 9; k++) {
				dp[i][(j + k) % D] = (dp[i][(j + k) % D] + dp[i - 1][j]) % mod;
			}
		}
	}
//	for (int i = 0; i < D; i++) cout << "dp[0][" << i << "] = " << dp[0][i] << endl;
	long long cnt = 0;
	long long acc = 0;
	for (int i = K.size() - 1; i >= 0; acc = (acc + K[i--] - '0') % D) {
		for (int j = 0; j < K[i] - '0'; j++) {
			if (i > 0) cnt = (cnt + dp[i - 1][(20 * D - acc - j) % D]) % mod;
			else cnt = (cnt + ((acc + j) % D == 0)) % mod;
		}
	}
	cnt = (cnt + (acc % D == 0) + mod - 1LL) % mod;
	cout << cnt << endl;
}
