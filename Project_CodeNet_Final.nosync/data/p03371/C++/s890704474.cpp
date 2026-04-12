#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

//const ll INF = 1e18L + 5;
//const int INF = 1e9 + 5;
//const double pi = 3.14159265358979323846;

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	c *= 2;
	ll ans = 0;
	if (c < a + b) {
		ll z = min(x, y);
		ans += c * z;
		x -= z; y -= z;
		if (x) {
			cout << ans + min(a, c) * x << endl;
		} else {
			cout << ans + min(b, c) * y << endl;
		}
	} else {
		cout << x * a + y * b << endl;
	}
}