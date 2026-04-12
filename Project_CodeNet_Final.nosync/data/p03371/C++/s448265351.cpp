#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_abc095() {
	ll a, b, c, x, y;
	ll ans = 0;

	cin >> a >> b >> c >> x >> y;

	ll ab = min(x, y);

	if (a + b > 2 * c) {
		ans += 2 * c * ab;
	}
	else {
		ans += (a + b) * ab;
	}

	if (x > y) {
		if (a > 2 * c) {
			ans += 2 * c * (x - y);
		}
		else {
			ans += a * (x - y);
		}
	}
	else {
		if (b > 2 * c) {
			ans += 2 * c * (y - x);
		}
		else {
			ans += b * (y - x);
		}
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc095();

	return 0;
}