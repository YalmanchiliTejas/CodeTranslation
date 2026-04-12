#include <bits/stdc++.h>
#define MAX (ll)(5e5 + 7)
#define INF (ll)(1e18 + 7)
#define MOD (ll)(1e9 + 7)

using namespace std;
using ll = long long;
using cd = complex<double>;

void f_io () {
	ios_base :: sync_with_stdio (false);
	cin.tie (nullptr);
}
ll ind[MAX];
int main () {
	ll n, x, m;
	cin >> n >> x >> m;
	vector<ll> ve;
	ve.push_back (x);
	ll st = 0;
	fill (ind, ind + MAX, -1);
	for (ll i = 2; i <= m; i++) {
		ll nw = (ve.back () * 1LL * ve.back ()) % m;
		if (ind[nw] >= 0) {
			st = ind[nw];
			break;
		}
		else {
			ind[nw] = ve.size ();
			ve.push_back (nw);
		}
	}
	ll ans = 0;
	for (ll i = 1; i < ve.size (); i++) {
		ve[i] += ve[i - 1];
	}
	if (min (st, n)) {
		ans = ve[min (st, n) - 1];
	}
	n -= min (n, st);
	ll aa = ans;
	if (n) {
		ans += (n / ((ll)ve.size () - st)) * 1LL * (ve.back () - ans);
		ll r = (n % ((ll)ve.size () - st));
		if (st + r - 1 >= 0) {
			ans += (ve[st + r - 1] - aa);
		}
	}
	cout << ans << "\n";
}
