#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> v(n);
	for (long long i = 0; i < n; i++)cin >> v[i];
	vector<vector<long long>> dp(n, vector<long long>(n));
	for (long long l = n - 1; l >= 0; l--) {
		for (long long r = l; r < n; r++) {
			if (l == r) dp[l][r] = v[l];
			else {
				dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
			}
		}
	}
		cout << dp[0][n - 1];
}