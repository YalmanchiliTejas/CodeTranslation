#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<long long> pref(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) pref[i] = a[i];
		else pref[i] = pref[i - 1] + a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * ((pref[n - 1] - pref[i]) % mod) % mod;
		ans %= mod;
	}
	cout << ans << "\n";
}
