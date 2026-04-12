#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

void fail() {
	cout << -1 << endl;
	exit(0);
}

bool get(ll x, ll k) {
	return (x >> k) & 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl s(n), t(n), u(n), v(n);
	FOR(i,0,n) cin >> s[i];
	FOR(i,0,n) cin >> t[i];
	FOR(i,0,n) cin >> u[i];
	FOR(i,0,n) cin >> v[i];
	
	vvl res(n, vl(n));

	FOR(k,0,64) {
		vector<vector<int>> a(n, vector<int>(n, -1));
		
		auto fix = [&](ll i, ll j, int x) {
			if (a[i][j] != -1) {
				if (a[i][j] != x) fail();
			} else {
				a[i][j] = x;
			}
		};

		FOR(i,0,n) if (s[i] != get(u[i],k)) {
			FOR(j,0,n) fix(i, j, get(u[i],k));
		}
		
		FOR(j,0,n) if (t[j] != get(v[j],k)) {
			FOR(i,0,n) fix(i, j, get(v[j],k));
		}
		
		set<ll> is, js;
		FOR(i,0,n) FOR(j,0,n) if (a[i][j] == -1) {
			is.insert(i), js.insert(j);
		}
		
		if (sz(is) == 1) {
			ll i = *begin(is);
			for (ll j: js) {
				bool sat = false;
				FOR(ii,0,n) if (ii != i && a[ii][j] == t[j]) sat = true;
				fix(i, j, sat ? s[i] : t[j]);
			}
		} else if (sz(js) == 1) {
			ll j = *begin(js);
			for (ll i: is) {
				bool sat = false;
				FOR(jj,0,n) if (jj != j && a[i][jj] == s[i]) sat = true;
				fix(i, j, sat ? t[j] : s[i]);
			}
		} else {
			ll ci = 0;
			for (ll i: is) {
				ll cj = 0;
				for (ll j: js) {
					fix(i, j, (ci+cj)%2);
					cj++;
				}
				ci++;
			}
		}
		
		FOR(i,0,n) FOR(j,0,n) {
			assert(a[i][j] != -1);
			res[i][j] |= ll(a[i][j]) << k;
		}
	}
	
	FOR(i,0,n) {
		ll x = res[i][0];
		FOR(j,0,n) if (!s[i]) x = x & res[i][j]; else x = x | res[i][j];
		if (x != u[i]) fail();
	}
	FOR(j,0,n) {
		ll x = res[0][j];
		FOR(i,0,n) if (!t[j]) x = x & res[i][j]; else x = x | res[i][j];
		if (x != v[j]) fail();
	}

	FOR(i,0,n) FOR(j,0,n) cout << res[i][j] << " \n"[j+1==n];

}

