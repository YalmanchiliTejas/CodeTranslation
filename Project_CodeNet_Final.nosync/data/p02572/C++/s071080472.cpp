#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];
	ll ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		ans = (ans + a[i] * a[i + 1]) % MOD;
		a[i] = (a[i] + a[i + 1]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}