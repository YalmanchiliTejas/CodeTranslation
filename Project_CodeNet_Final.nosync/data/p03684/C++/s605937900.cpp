//This is getting accepted!
// I HATE BUG
// God Of The Bugs
// 12/11/2016
#include<bits/stdc++.h>

using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ll long long
#define sz(a) ((int)(a).size())
#define __builtin_popcount __builtin_popcounll
#define ld long double

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}
template<class T> T sqr(T x) { return x * x; }

inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

int par[MAXN], _size[MAXN];
vector<pii> X, Y;
vector<pair<int, pii> > ed;
int n, x[MAXN], y[MAXN];

int getpar(int u) {
	while (u != par[u]) {
		par[u] = par[par[u]];
		u = par[u];
	}
	return u;
}

int chich(int a, int b) {
	int A = getpar(a), B = getpar(b);
	if (A == B) return 0;
	if (_size[A] > _size[B]) swap(A, B);
	par[A] = B;
	_size[B] += _size[A];
	return 1;
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("inp.txt", "r", stdin);
////    freopen("out.txt", "w", stdout);
//#endif

	cin >> n;
	
	for (int i=0; i<n; i++) cin >> x[i] >> y[i];
	
	for (int i=0; i<n; i++) {
		X.pb(mp(x[i], i));
		Y.pb(mp(y[i], i));
	}
	
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	
	for (int i=1; i<n; i++) {
		ed.pb(mp(X[i].FI - X[i - 1].FI, mp(X[i].SE, X[i - 1].SE)));
		ed.pb(mp(Y[i].FI - Y[i - 1].FI, mp(Y[i].SE, Y[i - 1].SE)));
	}

	for (int i=0; i<n; i++) {
		par[i] = i;
		_size[i] = 1;
	}
	sort(ed.begin(), ed.end());
	
	ll ans = 0;
	for (int i=0; i<sz(ed); i++) {
		if (chich(ed[i].SE.FI, ed[i].SE.SE)) ans += (ll) ed[i].FI;
	}
	
	cout << ans;
}
