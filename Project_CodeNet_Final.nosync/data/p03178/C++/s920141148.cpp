#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll dp[2][100][2];
int main() {
	string K;
	int D;
	cin >> K >> D;
	int N = K.size();
	dp[0][0][0] = 1;
	for (int i = 0; i < N; i++) {
		int d = K[i] - '0';
		for (int j = 0; j < D; j++) {
			for (int k = 0; k <= d; k++) {
				(dp[(i + 1) & 1][(j + k) % D][k < d] += dp[i & 1][j][0]) %= MOD;
			}
			for (int k = 0; k < 10; k++) {
				(dp[(i + 1) & 1][(j + k) % D][1] += dp[i & 1][j][1]) %= MOD;
			}
		}
		for (int j = 0; j < D; j++) dp[i & 1][j][0] = dp[i & 1][j][1] = 0;
	}
	ll ans = dp[N & 1][0][0];
	(ans += dp[N & 1][0][1]) %= MOD;
	(ans += MOD - 1) %= MOD;
	cout << ans << endl;
}