#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll power(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll sub(ll a, ll b) {
	return ((a - b) + mod) % mod;
}

void solve() {
	int n; cin >> n;
	vector<ll> v(n);
	for (ll &i : v)cin >> i;
	ll sum = accumulate(v.begin(), v.end(), 0ll) % mod;
	sum = sum * sum % mod;
	for (ll i : v)sum = sub(sum, i * i % mod);
	cout << sum*power(2, mod - 2) % mod;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t; cin >> t;
	// while (t--)
	solve();

}