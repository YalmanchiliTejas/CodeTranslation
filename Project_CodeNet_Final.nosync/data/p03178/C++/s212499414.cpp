#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 100010;
const int MAXD = 110;
const int MOD = 1000000007;

int N, D;
string S;
int dp[MAXN][MAXD][2];


int main() {

	cin >> S;
	cin >> D;
	N = S.length();

	dp[0][0][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int mod = 0; mod < D; mod++) {
			int last_digit = S[i - 1] - '0';
			for (int digit = 0; digit <= 9; digit++) {
				int sum = (mod + digit) % D;
				dp[i][sum][1] = (dp[i][sum][1] + dp[i - 1][mod][1]) % MOD;
			}

			for (int digit = 0; digit < last_digit; digit++) {
				int sum = (mod + digit) % D;
				dp[i][sum][1] = (dp[i][sum][1] + dp[i - 1][mod][0]) % MOD;
			}
			int sum = (mod + last_digit) % D;
			dp[i][sum][0] = (dp[i][sum][0] + dp[i - 1][mod][0]) % MOD;
		}
	}
	int64_t ans = (dp[N][0][0] + dp[N][0][1]) % MOD;
	if (ans == 0) ans = MOD - 1;
	else ans --;
	cout << ans;
	return 0;
}