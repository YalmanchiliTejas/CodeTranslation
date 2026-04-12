#include <iostream>
#include <string>
using namespace std;

string S; long long N, dp[10009][109][2], mod = 1000000007;

int main() {
	cin >> S >> N;
	dp[0][0][1] = 1;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 10; k++) {
				if ((int)(S[i] - '0') > k) {
					dp[i + 1][(j + k) % N][0] += dp[i][j][0]; dp[i + 1][(j + k) % N][0] %= mod;
					dp[i + 1][(j + k) % N][0] += dp[i][j][1]; dp[i + 1][(j + k) % N][0] %= mod;
				}
				else if ((int)(S[i] - '0') == k) {
					dp[i + 1][(j + k) % N][0] += dp[i][j][0]; dp[i + 1][(j + k) % N][0] %= mod;
					dp[i + 1][(j + k) % N][1] += dp[i][j][1]; dp[i + 1][(j + k) % N][1] %= mod;
				}
				else {
					dp[i + 1][(j + k) % N][0] += dp[i][j][0]; dp[i + 1][(j + k) % N][0] %= mod;
				}
			}
		}
	}
	long long ret = dp[S.size()][0][0] + dp[S.size()][0][1]; ret--; ret += mod; ret %= mod;
	cout << ret << endl;
	return 0;
}