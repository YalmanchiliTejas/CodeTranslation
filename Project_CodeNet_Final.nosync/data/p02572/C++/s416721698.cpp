#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll s = 0, res = 0;
	ll mod = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		s += a[i];
		res += a[i] * ((sum - s) % mod);
		if (res >= mod) res %= mod;
	}
	cout << res;
}
// s = a1a2 + a1a3 + ... + a1an // a1(sum - a1)
//	+  a2a3 + a2a4 + ... + a2an // a2(sum - a1 - a2)
//  ... 
//  + a(n - 1)an //
// sum(1...n)(ai(sum - sum(1...i)))
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}