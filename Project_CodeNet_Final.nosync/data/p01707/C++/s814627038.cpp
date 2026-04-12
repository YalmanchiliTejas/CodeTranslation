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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> N >> M >> K, N) {
		vector<vector<long long int>>dp(N + 2, vector<long long int>(N + 2010));
		dp[0][0] = 1;
		dp[0][1] = -1;
		for (int i = 0; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= MOD;
				//cout << j << " " << dp[i][j] << endl;
			}
			for (int j = 0; j <= N; j++) {
				dp[i + 1][j + 1] += dp[i][j];
				dp[i + 1][j + 1] %= MOD;
				dp[i + 1][j + K] += MOD - dp[i][j];
				dp[i + 1][j + K] %= MOD;
			}
		}
		long long int ans = 0;
		for (int i = 1; i <= N; i++) {
			long long int by = 1;
			long long int num = M - i;
			if (num < 0)continue;
			for (int j = 1; j <= i; j++) {
				by *= (num + j)%MOD;
				by %= MOD;
				by *= power(j, MOD - 2, MOD);
				by %= MOD;
			}
			ans += by * dp[i][N];
			ans %= MOD;
		//	cout << i << " " << ans << endl;
		}
		cout << ans << endl;
	}
}
