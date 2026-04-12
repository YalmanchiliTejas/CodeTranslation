#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const ll mod = 1e9 + 7;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector<ll>v(n + 1);
	vector<ll>cpy(n + 1);
	v[0] = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> v[i];
		cpy[i] = v[i];
		if (i >= 2)
			v[i] += v[i - 1];
	}
	ll ans = 0;
	for (ll i = 1; i <= n ; i++) {
		ll have = cpy[i];
		ll sum = v[n] - v[i];
		sum %= mod;
		have %= mod;
		ans += (have * sum) % mod;
		if (ans < 0)ans += mod;
		ans %= mod;
	}
	if (ans < 0)ans += mod;
	cout << ans % mod << endl;
}