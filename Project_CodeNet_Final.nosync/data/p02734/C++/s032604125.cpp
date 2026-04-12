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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<vector<long long int>>dp(N + 1, vector<long long int>(M + 1));
	for (int i = 0; i < N; i++) {
		if (v[i] <= M)dp[i + 1][v[i]] = i + 1;
		for (int j = 0; j <= M; j++) {
			if (j != M)dp[i + 1][j] += dp[i][j];
			if (j >= v[i])dp[i + 1][j] += dp[i][j - v[i]];
			dp[i + 1][j] %= MOD;
		}
	}
	long long int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += dp[i][M] * (N - i + 1) % MOD;
	}
	cout << ans % MOD << endl;
}
