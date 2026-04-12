#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V v) { writer(x, ' '); writer(y, ' '); writer(z, ' '); writer(v, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
ll mod_inv(ll a, ll m) { ll x, y; extgcd<ll>(a, m, x, y); return (m + x % m) % m; }

#ifdef _DEBUG
template <typename ... Args>
void debugPrintf(const char *format, Args const & ... args) {
	fprintf(stdout, format, args ...);
	fflush(stdout);
}
#else
#define debugPrintf(...)
#endif

const int MOD = ten(9) + 7;

struct val_t {
	ll v;
	val_t() {}
	val_t(ll v) : v(v) {}
	static val_t zero() {
		return { (ll)-1e17 };
	}
	bool is_zero() const {
		return v == (ll)-1e17;
	}
	val_t operator+ (const val_t& r) const {
		if (is_zero()) return r;
		if (r.is_zero()) return *this;

		val_t ret;
		ret.v = max(v, r.v);
		return ret;
	}
};

struct lazy_t {
	ll add;
	lazy_t() {}
	lazy_t(ll add) : add(add) {}
	static lazy_t zero() {
		return{ 0 };
	}
	bool is_zero() const {
		return add == 0;
	}
	//lazy_t operator+ (lazy_t& to) {
	lazy_t go_down(const lazy_t& to) {
		if (is_zero()) return to;
		if (to.is_zero()) return *this;
		lazy_t ret;
		ret.add = to.add + add;
		return ret;
	}
	val_t resolve(const val_t& val, int l, int r) {
		if (is_zero()) return val;
		return val_t(add + val.v);
	}
};

class lazy_seg_tree {

	vector<val_t> dat;
	vector<lazy_t> lazy;
	int n;

	void propagate(int i) {
		dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
	}

	void propagate_if_lazy(int k, int l, int r) {
		if (lazy[k].is_zero()) return;
		dat[k] = lazy[k].resolve(dat[k], l, r);
		lazy[2 * k + 1] = lazy[k].go_down(lazy[2 * k + 1]);
		lazy[2 * k + 2] = lazy[k].go_down(lazy[2 * k + 2]);
		lazy[k] = lazy_t::zero();
	}

	val_t query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return val_t::zero();
		if (a <= l && r <= b) return lazy[k].resolve(dat[k], l, r);

		propagate_if_lazy(k, l, r);
		const int m = (l + r) / 2;
		val_t vl = query(a, b, 2 * k + 1, l, m);
		val_t vr = query(a, b, 2 * k + 2, m, r);
		return vl + vr;
	}

	val_t update(int a, int b, lazy_t x, int k, int l, int r) {
		if (r <= a || b <= l) return lazy[k].resolve(dat[k], l, r);
		if (a <= l && r <= b) {
			lazy[k] = x.go_down(lazy[k]);
			return lazy[k].resolve(dat[k], l, r);
		}

		propagate_if_lazy(k, l, r);
		const int m = (l + r) / 2;
		val_t vl = update(a, b, x, 2 * k + 1, l, m);
		val_t vr = update(a, b, x, 2 * k + 2, m, r);
		return dat[k] = vl + vr;
	}

public:
	lazy_seg_tree(int osize) {
		n = 1;
		while (n < osize) n <<= 1;
		dat.assign(2 * n - 1, val_t::zero());
		lazy.assign(2 * n - 1, lazy_t::zero());
		for (int i = 0; i < osize; i++) dat[n - 1 + i] = val_t(0);
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	val_t query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	void update(int a, int b, lazy_t x) {
		update(a, b, x, 0, 0, n);
	}
};

int main() {
	int n, m; reader(n, m);
	vector<vector<Pii>> q(n + 2);

	FOR(i, m) {
		int l, r, a; reader(l, r, a);
		q[r + 1].emplace_back(l, a);
	}

	lazy_seg_tree lst(n + 2);
	for(int i = 1; i < n + 2; i++) {
		for (auto& la : q[i]) {
			lst.update(la.first, i , lazy_t(la.second));
		}
		ll val = lst.query(0, i).v;
		lst.update(i, i + 1, lazy_t(val));
	}
	ll ans = lst.query(n + 1, n + 2).v;
	writerLn(ans);

	return 0;
}
