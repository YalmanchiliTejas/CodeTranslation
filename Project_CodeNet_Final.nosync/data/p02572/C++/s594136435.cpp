#include <iostream>
#define int long long

using namespace std;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

int a[N];

signed main() {
	int n;
	cin >> n;
	
	int sum = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		sum -= a[i];
		ans += a[i] * (sum % MOD);
		ans %= MOD;
	}
	
	cout << ans << '\n';
	
	return 0;
}