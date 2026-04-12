#include <iostream>
#include <cassert>
using namespace std;

// https://atcoder.jp/contests/abc159/tasks/abc159_f

const int N = 3008;
const int MOD = 998244353;
int a[N];
int dp[N][N]; // dp[i][j] = sum of ways to choose L and then make sum j with first i elements

int n, target;
int main() {
	cin >> n >> target;
	assert(n < N);
	assert(target < N);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		assert(a[i] < N);
	}

	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int s = 0; s <= target; s++) {
			dp[i][s] = 0;

			if (i > 0) {
				// don't use a[i]
				dp[i][s] += dp[i-1][s];
			}

			if (s == a[i]) {
				// use a[i] as x_1
				// i + 1 ways to choose L
				dp[i][s] += i + 1;
			} else if (s > a[i] && i > 0) {
				// use a[i] as x_j, j > 1
				dp[i][s] += dp[i-1][s - a[i]];
			}

			dp[i][s] %= MOD;

			if (s == target) {
				// use i as R
				answer = (answer + dp[i][s]) % MOD;
			}
		}
	}

	cout << answer << "\n";
}
