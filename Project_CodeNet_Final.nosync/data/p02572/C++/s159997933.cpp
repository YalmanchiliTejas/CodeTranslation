#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		sum %= mod;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		sum -= a[i];
		sum += mod;
		sum %= mod;
		ans += (a[i] * sum) % mod;
		ans %= mod;
	}
	cout << ans;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		cout << endl;
	}
}