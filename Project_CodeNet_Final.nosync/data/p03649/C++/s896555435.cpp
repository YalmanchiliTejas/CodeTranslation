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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

void go(vl &a) {
	ll n = sz(a);
	ll i = 0;
	FOR(j,0,n) if (a[j] > a[i]) i = j;

	a[i] -= n;
	FOR(j,0,n) if (j != i) a[j]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vl c(n);
	
	ll res = 0;
	bool done = false;
	while (!done) {
		done = true;
		
		FOR(i,0,n) {
			if (a[i] + res - (n+1)*c[i] <= n-1) continue;
			ll x = a[i] + res - (n+1)*(c[i]) - (n-1);
			c[i] += (x+n-1)/n, res += (x+n-1)/n;
			done = false;
		}
	}
	cout << res << endl;



/*sort(all(a));
	reverse(all(a));
	
	ll res = 0;
	FOR(k,1,n+1) {
		sort(all(a));
		reverse(all(a));
		ll x = (a[0]-a[k])/(n+k);

		res += x*k;
		FOR(i,0,k) a[i] -= x*n;
		FOR(i,k,n) a[i] += x*k;

		FOR(i,0,n) cerr << a[i] << " ";
		cerr << res << endl;
	}
	
	ll amax = -oo;
	FOR(i,0,n) amax = max(amax,a[i]);
	cout << res << endl;*/
}

