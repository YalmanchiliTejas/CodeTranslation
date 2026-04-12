#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : abs(x); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

ll solve(ll n, ll x, const vector<ll> &a, const vector<ll> &p) {
	if (n == 0LL) {
		return x > 0LL;
	} else if (x <= a[n - 1LL] + 1LL) {
		return solve(n - 1LL, x - 1LL, a, p);
	} else {
		return p[n - 1LL] + 1LL + solve(n - 1LL, x - 2LL - a[n - 1LL], a, p);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, x;
	cin >> n >> x;

	vector<ll> a(n + 1), p(n + 1);
	a[0] = p[0] = 1;
	for (ll i = 0; i < n; i++) {
		a[i + 1] = a[i] * 2 + 3;
		p[i + 1] = p[i] * 2 + 1;
	}


	ll ans = solve(n, x, a, p);
	cout << ans << endl;
	return 0;
}
