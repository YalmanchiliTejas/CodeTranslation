#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

vector<ll> a;
vector<ll> p;

ll solve(ll n, ll x) {
	if (n == 0 && x >= 1) {
		return 1;
	} else if (x == 1) {
		return 0;
	} else if (1 <= x && x <= 1 + a[n - 1]) {
		return solve(n - 1, x - 1);
	} else if (x == a[n - 1] + 2) {
		return p[n - 1] + 1;
	} else if (2 + a[n - 1] < x <= 2 + 2 * a[n - 1]) {
		return p[n - 1] + 1 + solve(n - 1, x - 2 - a[n - 1]);
	} else if (x == a[n - 1] + 3) {
		return 2 * p[n - 1] + 1;
	}
}

int main() {
	ll n, x;
	cin >> n >> x;
	a.resize(n + 1, 0);
	p.resize(n + 1, 0);
	a[0] = 1;
	p[0] = 1;
	REP(i, n) {
		a[i] = 2 * a[i - 1] + 3;
		p[i] = 2 * p[i - 1] + 1;
	}
	ll ans = solve(n, x);
	cout << ans << endl;
	return 0;
}