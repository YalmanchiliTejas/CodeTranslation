#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int nax = 2e5 + 100;

int n;
int a;
vector <ll> v[nax];
ll x[nax], y[nax];
ll z[nax];


int main() {
	scanf ("%d", &n);
	rep(i, 0, n - 1) {
		scanf ("%d", &a);
		v[i / 2].pb(a);
	}
	int g = (n - 2) / 2;
	rep(i, 0, g) {
		x[i] = (i ? x[i - 1] : 0) + v[i][0];
		y[i] = (i ? y[i - 1] : 0) + v[i][1];
		z[i] = -1e18;
		if (i) z[i] = z[i - 1];
		z[i] = max(z[i], -y[i] + x[i]);
	}
	ll res = -1e18;
	rep(i, 0, g) {
		ll s = y[g];
		if (i) s -= y[i - 1];
		if (i) s += x[i - 1];
		res = max(res, s);
	}
	res = max(res, y[g]);
	res = max(res, x[g]);
	if (n % 2 == 1) {
		rep(i, 0, g) {
			ll s = v[g + 1][0];
			s += x[g] - x[i];
			if (i) {
				s += y[i - 1];
				s += z[i - 1];
			}
			res = max(res, s);
		}
	}
	printf ("%lld", res);
	
		
	
	return 0;
}
