#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FSP(x) fixed << setprecision(x)
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;
const long double PI = acosl(-1);
void Yes() {cout << "Yes\n";}
void No() {cout << "No\n";}
void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//const ll P = 1e9 + 7;
	//const ll P = 998244353;

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	sort(ALL(a));
	ll ans = 0;
	if (n % 2 == 0) {
		for (ll i = 0; i < n; i++) {
			if (i < n / 2) ans -= a[i] * 2;
			else ans += a[i] * 2;
		}
		ans -= a[n / 2];
		ans += a[n / 2 - 1];
	} else {
		for (ll i = 0; i < n; i++) {
			if (i < n / 2 + 1) ans -= a[i] * 2;
			else ans += a[i] * 2;
		}
		ans += a[n / 2];
		ans += a[n / 2 - 1];
		ll subans = 0;
		for (ll i = 0; i < n; i++) {
			if (i < n / 2) subans -= a[i] * 2;
			else subans += a[i] * 2;
		}
		subans -= a[n / 2];
		subans -= a[n / 2 + 1];
		ans = max(ans, subans);
	}
	cout << ans << endl;
}