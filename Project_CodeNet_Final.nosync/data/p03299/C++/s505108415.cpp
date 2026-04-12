#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int binpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) cin >> h[i];
	vector<int> dp = { 2 };
	int firstlow = (n == 1 ? 1 : h[1]);
	dp[0] = 1LL * dp[0] * binpow(2, max(h[0] - firstlow, 0)) % mod;
	for (int i = 1; i < n; ++i) {
		vector<int> ndp(i + 1);
		int low = (i == n - 1 ? 1 : h[i + 1]);
		if (h[i] <= low) {
			for (int j = 0; j < i; ++j) {
				ndp[j] = dp[j];
				ndp[i] = (ndp[i] + dp[j]) % mod;
			}
		}
		else {
			int mx = min(h[i - 1], h[i]);
			int s = 0;
			for (int j = i - 1; j >= 0; --j) {
				mx = min(mx, (j == 0 ? 1 : h[j - 1]));
				ndp[j] = 1LL * dp[j] * binpow(2, h[i] - max(low, mx)) % mod;
				s = (s + dp[j]) % mod;
			}
			ndp[i] = 1LL * s * binpow(2, h[i] - max(min(h[i - 1], h[i]), low)) % mod;
		}
		dp = ndp;
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum = (sum + dp[i]) % mod;
	}
	cout << sum << '\n';
	return 0;
}