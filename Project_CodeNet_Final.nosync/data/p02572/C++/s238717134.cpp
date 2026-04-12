#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	int n;
	cin >> n;
	int a[n+5];
	long long pref = 0LL, ans = 0LL;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pref += a[i];
	}
	for (int i = 0; i < n; ++i) {
		pref -= a[i];
		ans = (ans + (a[i]%MOD)*(pref%MOD)) % MOD;
		ans = ans % MOD;
	}
	if(ans < 0)
		ans += MOD;
	cout << ans << '\n';
	return 0;
}