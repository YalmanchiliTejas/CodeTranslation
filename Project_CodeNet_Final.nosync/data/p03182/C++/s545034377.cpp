#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 300010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

struct T {
	ll v;
	T(ll v = 0) : v(v) {}
	T operator+(const T& t) { return T(max(v, t.v)); } //when getting value
	void operator+=(const T& t) { v = v + t.v; } //when updating value
	friend ostream& operator<<(ostream& out, const T& t) {
		out << t.v; return out;
	}
};

struct segtree { //use BIT if you can
	int n; vector<T> sum, lazy;
	void init(int mx) {
		n = 1;
		while(n < mx) n *= 2;
		sum = vector<T>(n * 2);
		lazy = vector<T>(n * 2);
	}
	segtree(int mx = 0) { init(mx); }
	inline void lazy_eval(int k, int l, int r) {
		if(lazy[k].v != T().v) {
			sum[k * 2 + 1] += lazy[k];
			lazy[k * 2 + 1] += lazy[k];
			sum[k * 2 + 2] += lazy[k];
			lazy[k * 2 + 2] += lazy[k];
			lazy[k] = T();
		}
	}
	void app(int a, int b, T s, int k, int l, int r) {
		if(b <= l || r <= a) return;
		if(a <= l && r <= b) {
			sum[k] += s; //here too
			lazy[k] += s;
		}
		else {
			lazy_eval(k, l, r);
			app(a, b, s, k * 2 + 1, l, (l + r) / 2);
			app(a, b, s, k * 2 + 2, (l + r) / 2, r);
			sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
		}
	}
	T ga(int a, int b, int k, int l, int r) {
		if(b <= l || r <= a) return T(-linf);
		if(a <= l && r <= b) return sum[k];
		else {
			lazy_eval(k, l, r);
			T lv = ga(a, b, k * 2 + 1, l, (l + r) / 2);
			T rv = ga(a, b, k * 2 + 2, (l + r) / 2, r);
			return lv + rv;
		}
	}
	void show() {
		vector<T> tmp;
		rep(i, 0, n) tmp.push_back(get(i, i + 1));
		debug(tmp);
	}
	T get(int a, int b) { return ga(a, b, 0, 0, n); } //[a, b)
	void update(int a, int b, T s) { app(a, b, s, 0, 0, n); } //[a, b)
};


int N, M;
vector<pl> Q[MAX_N]; //left, cost


void solve() {
	cin >> N >> M;
	rep(i, 0, M) {
		int l, r; ll cost;
		cin >> l >> r >> cost; l--;
		Q[r].pb(pl(l, cost));
	}
	segtree seg(N);
	seg.update(0, N, T(-linf));
	rep(i, 0, N) {
		ll v = max(0ll, seg.get(0, i).v);
		seg.update(i, i + 1, linf + v);
		rep(j, 0, sz(Q[i + 1])) {
			pl p = Q[i + 1][j];
			seg.update(p.fst, i + 1, T(p.sec));
		}
		// seg.show();
	}
	cout << max(0ll, seg.get(0, N).v) << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

