#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
constexpr long long MOD = 998244353;

int main() {
	int n, s; cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<long long>> dp(s + 3030, vector<long long>(3));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		vector<vector<long long>> next(s + 3030, vector<long long>(3));
		for (int j = 0; j <= s; ++j) {
			// 状態維持
			next[j][0] += dp[j][0];
			next[j][1] += dp[j][1]; // 足さない
			next[j + a[i]][1] += dp[j][1]; // 足す
			next[j][2] += dp[j][2];
			// 区間を始める
			next[j][1] += dp[j][0]; // 加算なし
			next[j + a[i]][1] += dp[j][0]; // 加算あり
			// 区間を終える
			next[j][2] += dp[j][0] + dp[j][1]; // 加算なし
			next[j + a[i]][2] += dp[j][0] + dp[j][1]; // 加算あり

			next[j][0] %= MOD;
			next[j][1] %= MOD;
			next[j][2] %= MOD;
			next[j + a[i]][1] %= MOD;
			next[j + a[i]][2] %= MOD;
		}
		dp = next;
	}
	cout << dp[s][2];
	return 0;
}