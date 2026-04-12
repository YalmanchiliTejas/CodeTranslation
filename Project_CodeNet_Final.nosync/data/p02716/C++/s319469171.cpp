#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	M = (N & 1) + 1;
	if (N == 2) {
		cout << max(v[0], v[1]) << endl;
		return 0;
	}
	vector<vector<long long int>>dp(N, vector<long long int>(M + 1, -MOD * MOD));
	if (N & 1) {
		dp[0][2] = v[0];
		dp[1][1] = v[1];
		dp[2][0] = v[2];
		dp[2][2] = v[0] + v[2];
	}
	else {
		dp[0][1] = v[0];
		dp[1][0] = v[1];
		dp[2][1] = v[0] + v[2];
	}
	long long int ans = -MOD * MOD;
	for (int i = 3; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k <= j; k++) {
				int a = i - 2 - (j - k);
				if (a < 0)continue;
				dp[i][k] = max(dp[i][k], dp[a][j] + v[i]);
		//			cout << i << " " << k << " " << dp[i][k] << endl;
			}
		}
	}
	for (int i = N - 3; i < N; i++) {
		//cout << i << " " << M - N + i + 1 << endl;
		if (M - N + i + 1 >= 0) {
			for (int j = 0; j <= M - N + i + 1; j++) {
				if (i == N - 1 && j == M && j == 2)continue;
				if (i == N - 3 && j == 0 && M == 2)continue;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans << endl;
}