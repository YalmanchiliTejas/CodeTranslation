#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, x, m;
	cin >> n >> x >> m;

	vl a(2*m);
	a[0] = x;
	FOR(i,1,2*m) a[i] = a[i-1]*a[i-1] % m;

	if (n <= 2*m) {
		ll res = 0;
		FOR(i,0,n) res += a[i];
		cout << res << endl;
	} else {
		ll res = 0;
		FOR(i,0,m) res += a[i];
		n -= m;
		ll block = a[m];
		ll j = m+1;
		while (j < 2*m && a[j] != a[m]) block += a[j++];
		res += n/(j-m) * block;
		n %= (j-m);
		FOR(i,0,n) res += a[m+i];
		cout << res << endl;
	}
}

