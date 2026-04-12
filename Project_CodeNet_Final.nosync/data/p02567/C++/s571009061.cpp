#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
#include<cassert>
using namespace std;
#include<atcoder/all>
using namespace atcoder;


#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 4000001;
const long double eps = 1E-14;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

using mint = modint998244353;

typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

/////////////////////////////////////
ll v;
bool b(ll x) { return x < v; }
ll e() { return -1; }

int main() {
	ll N, Q;
	cin >> N >> Q;
	vll a(N);
	rep(i, N)cin >> a[i];
	segtree<ll, max, e> sg(a);

	rep(q, Q) {
		ll t;
		cin >> t;

		if (t == 1) {
			ll x, vv;
			cin >> x >> vv;
			x--;
			sg.set(x, vv);
		}

		else if (t == 2) {
			ll l, r;
			cin >> l >> r;
			l--; r--;
			cout << sg.prod(l, r + 1) << endl;
		}

		else {
			ll x;
			cin >> x >> v;
			x--;
			ll ans = sg.max_right<b>(x);
			cout << ans + 1 << endl;
		}
	}
}
