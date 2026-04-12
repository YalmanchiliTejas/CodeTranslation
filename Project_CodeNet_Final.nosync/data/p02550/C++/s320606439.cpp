#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
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

	ll n, x, m;
	cin >> n >> x >> m;
	vector<ll> a(m * 2 + 5);
	a[0] = x;
	rep(i, m * 2 + 4) a[i + 1] = a[i] * a[i] % m;

	int s = 0;
	for (int i = m * 2 + 3; i >= 0; i--) {
		if (a[i] == a[m * 2 + 4]) {
			s = m * 2 + 4 - i;
			break;
		}
	}

	int st = -1;
	rep(i, m * 2 - s) {
		if (a[i] == a[i + s]) {
			st = i;
			break;
		}
	}

	rep(i, m * 2 + 4) a[i + 1] += a[i];
	if (n <= 2 * m + 4)
		cout << a[n - 1] << endl;
	else if (st == 0) {
		ll ans = a[s - 1] * (n / s);
		if (n % s) ans += a[n % s - 1];
		cout << ans << endl;
	} else {
		ll ans = (a[st + s] - a[st]) * ((n - st) / s) + a[st - 1];
		if ((n - st) % s != 0) ans += a[(n - st) % s + st - 1] - a[st - 1];
		cout << ans << endl;
	}

	return 0;
}