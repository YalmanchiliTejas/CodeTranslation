#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
map<ll, ll>m;
vector<ll>v;
ll n, x, mod, s, len, st, ans = 0ll;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(10);
	cin >> n >> x >> mod;
	v.pb(x);
	m[x] = 1ll;
	s = x % mod;
	st = n + 1ll;
	for (ll i = 2ll; i <= n; i++) {
		s = (s * s) % mod;
		if (m.find(s) != m.end()) {
			st = m[s];
			len = i - m[s];
			break;
		}
		m[s] = i;
		v.pb(s);
	}
	for (ll i = 1ll, cnt; i <= 1ll * v.size(); i++) {
		if (i < st) {
			ans += v[i - 1ll];
			continue;
		}
		cnt = ((n - st + 1ll) / (len));
		cnt += (((n - st + 1ll) % (len) > i - st) ? 1ll : 0ll);
		ans += (v[i - 1ll] * cnt);
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}