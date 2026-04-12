#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, ans, r;
int x, m, s, t;
int a[100000];

int main() {
	cin >> n >> x >> m;
	fill(a, a + m, -1);
	r = n;
	for (int i = 0; i < n; ++i) {
		if (a[x] < 0) {
			a[x] = i;
			ans += x;
			x = (ll) x * x % m;
			--r;
		} else {
			s = a[x];
			t = i - a[x];
			break;
		}
	}
	ll c = 0;
	for (int i = 0; i < t; ++i) {
		c += x;
		x = (ll) x * x % m;
	}
	ans += c * (r / t);
	r %= t;
	for (int i = 0; i < r; ++i) {
		ans += x;
		x = (ll) x * x % m;
	}
	cout << ans << endl;
}
