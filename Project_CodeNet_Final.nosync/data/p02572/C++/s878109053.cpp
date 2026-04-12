#include <iostream>
#include <vector>
using namespace std;

using pll = pair<long, long>;
constexpr long MOD = 1000000007;

int main() {
	long n; cin >> n;
	vector<long> a(n, 0), b(n+1, 0);
	for (long i = 0; i < n; i++) {
		cin >> a[i];
		b[i+1] = a[i] + b[i];
	}

	long ans = 0;
	for (long i = 0; i < n-1; i++) {
		ans += (a[i] * ((b[n] - b[i+1]) % MOD)) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}
