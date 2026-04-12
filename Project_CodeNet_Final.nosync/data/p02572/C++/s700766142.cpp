#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll sum = 0;
	ll ans = 0;
	ll e = 1000000000+7;
	for (int i = 0; i < n; i++) {
		ans += (a[i] % e) * sum;
		ans %= e;
		sum += a[i] % e;
		sum %= e;
	}
	cout << ans << endl;
	return 0;
}