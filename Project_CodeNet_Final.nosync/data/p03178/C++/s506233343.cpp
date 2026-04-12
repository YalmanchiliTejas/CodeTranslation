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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	cin >> K;
	vector<vector<long long int>>dp(N, vector<long long int>(K));
	vector<vector<long long int>>tight(N, vector<long long int>(K));
	for (int i = 0; '0' + i < s[0]; i++) {
		dp[0][i%K] ++;
	}
	tight[0][(s[0] - '0')%K] ++;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < K; j++) {
			dp[i - 1][j] %= MOD;
			tight[i - 1][j] %= MOD;
			for (int k = 0; k < 10; k++) {
				dp[i][(j  + k) % K] += dp[i - 1][j];
			}
			for (int k = 0; k + '0' < s[i]; k++) {
				dp[i][(j  + k) % K] += tight[i - 1][j];
			}
			tight[i][(j  + s[i] - '0') % K] += tight[i - 1][j];
		}
	}
	long long int ans = tight.back().front() + dp.back().front() + MOD - 1;
	ans %= MOD;
	cout << ans << endl;
	return 0;
} 