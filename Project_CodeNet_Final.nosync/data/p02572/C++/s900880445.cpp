#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	ll m = 1e9+7;
	cin >> n;
	vector<ll> a(n), sum_a(n);
	rep(i,n) cin >> a[i];
	sum_a[0] = a[0];
	rep(i,n-1) {
		sum_a[i+1] = sum_a[i] + a[i+1];
		sum_a[i+1] %= m;
	}

	ll ans = 0;
	rep(i,n-1) {
		ans += a[i] * (sum_a[n-1] - sum_a[i] + m);
		ans %= m;
	}
	cout << ans << endl;

	return 0;
}
