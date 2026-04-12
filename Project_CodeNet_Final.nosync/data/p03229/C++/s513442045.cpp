#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	ll sum = 0;
	if (n % 2) {
		rep(i, (n + 1) / 2 - 2) sum += a[n - 1 - i] * 2 - a[i] * 2;
		sum += max(a[n / 2] + a[n / 2 + 1] - a[n / 2 - 1] * 2, a[n / 2 + 1] * 2 - a[n / 2] - a[n / 2 - 1]);
	} else {
		rep(i, n / 2 - 1) sum += a[n - 1 - i] * 2 - a[i] * 2;
		sum += a[n / 2] - a[n / 2 - 1];
	}
	cout << sum << endl;
	return 0;
}