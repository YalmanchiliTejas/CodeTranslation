#include <iostream>
#include <vector>
using namespace std;
int main() {
	long long n; cin >> n;
	vector<long long> a(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<long long> > dp(n, vector<long long>(n));
	for (long long i = 0; i < n; i++) {
		if (n % 2 == 0) {
			dp[i][i] = -a[i];
		} else {
			dp[i][i] = a[i];
		}
	}
	for (long long len = 2; len <= n; len++) {
		for (long long l = 0; l + len - 1 < n; l++) {
			long long r = l + len - 1;
			if (len % 2 == n % 2) {
				dp[l][r] = max(a[l] + dp[l + 1][r], a[r] + dp[l][r - 1]);
			} else {
				dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r]);
			}
		}
	}
	cout << dp[0][n - 1] ;
	return 0;
}