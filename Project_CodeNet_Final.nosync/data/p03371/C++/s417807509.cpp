//------------------------------------------------------------
#define MOD 1000000007

//------------------------------------------------------------
#if 1
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------
using ll = long long;
#define int ll

#define FOR(i, s, e) for (ll i = ll(s); i < (ll)e; ++i)
#define RFOR(i, s, e) for (ll i = ll(e) - 1; i >= ll(s); --i)
#define REP(i, n) for (ll i = 0, i##_size = n; i < i##_size; ++i)
#define RREP(i, n) for (ll i = ll(n) - 1; i >= 0; --i)

//------------------------------------------------------------
template <class T>
struct arr : public vector<T> {
	arr() {}
	arr(ll n, T v = T()) : vector<T>(n, v) {}
	void init(ll n, T v = T()) {
		this->clear();
		this->resize(n, v);
	}
	ll sz() const { return (ll)this->size(); }
	void pb(T v) { this->push_back(v); }
	void sort() { std::sort(this->begin(), this->end()); }
	void rsort() { std::sort(this->begin(), this->end(), greater<T>()); }
	void uniqueErase() {
		this->erase(std::unique(this->begin(), this->end()), this->end());
	}
};
using ints = arr<ll>;
using intss = arr<arr<ll>>;

template <class T>
struct que : public queue<T> {
	ll sz() const { return (ll)this->size(); }
	T popfront() {
		T v = this->front();
		this->pop();
		return v;
	}
};

template <class A, class B>
struct pr {
	union {
		A a;
		A key;
		A first;
		A x;
	};
	union {
		B b;
		B value;
		B second;
		B y;
	};

	pr() : a(A()), b(B()) {};
	pr(A a_, B b_) : a(a_), b(b_) {}
	pr(pr const& r) : a(r.a), b(r.b) {};
	pr(pair<A, B> const& r) : a(r.first), b(r.second) {};

	bool operator == (pr const& r) const {
		return a == r.a && b == r.b;
	}
	bool operator != (pr const& r) const {
		return !((*this) == r);
	}
	bool operator < (pr const& r) const {
		if (a == r.a) {
			return b < r.b;
		}
		return a < r.a;
	}

	pr operator + (pr v) const { return pr(x, y) += v; }
	pr operator - (pr v) const { return pr(x, y) -= v; }

	pr& operator += (pr v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	pr& operator -= (pr v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	friend istream& operator>>(istream& is, pr& p) {
		is >> p.a >> p.b;
		return is;
	}
};
using pint = pr<ll, ll>;
using pints = arr<pint>;

template <class K, class V>
struct mp : public map<K, V> {
	bool get(K const& k, V* v) {
		auto it = this->find(k);
		if (it != this->end()) {
			*v = it->second;
			return true;
		}
		return false;
	}
};

template <class T>
struct arr2 {
	vector<vector<T>> vec;

	arr2() {}
	arr2(int w, int h, T const& value = T()) { vec.resize(h, vector<T>(w, value)); }
	arr2(arr2 const& r) { vec = r.vec; }
	arr2(arr2&& r) { vec = move(r.vec); }
	arr2& operator=(arr2 const& r) { vec = r.vec; return *this; }
	arr2& operator=(arr2&& r) { vec = move(r.vec); return *this; }

	int width() const {
		return (int)vec[0].size();
	}
	int height() const {
		return (int)vec.size();
	}

	void init(int w, int h, T const& value = T()) {
		vec.clear();
		vec.resize(h, vector<T>(w, value));
	}
	T& operator()(int x, int y) { return vec.at(y).at(x); }
	T const& operator()(int x, int y) const { return vec.at(y).at(x); }

	T& operator()(pint p) { return vec.at(p.y).at(p.x); }
	T const& operator()(pint p) const { return vec.at(p.y).at(p.x); }
};

//------------------------------------------------------------
template <class T> void chmin(T& a, T b) { if (b < a) { a = b; } }
template <class T> void chmax(T& a, T b) { if (b > a) { a = b; } }

constexpr int gcd(int a, int b) {
	if (a < 0) { a = -a; }
	if (b < 0) { b = -b; }
	if (a == 0) { return b; }
	if (b == 0) { return a; }

	while (int c = a % b) {
		a = b;
		b = c;
	}
	return b;
}

//------------------------------------------------------------
struct bfs {
	ints froms;
	ints steps;

	bfs(int N, intss const& adjacency) {
		froms.init(N, -1);
		steps.init(N, -1);

		que<ll> queue;
		queue.push(0);
		froms[0] = 0;
		steps[0] = 0;

		while (queue.empty() == false) {
			ll p = queue.popfront();

			for (ll n : adjacency[p]) {
				if (froms[n] != -1) {
					continue;
				}

				froms[n] = p;
				steps[n] = steps[p] + 1;
				queue.push(n);
			}
		}
	}
};

//------------------------------------------------------------
template <int M>
struct modint {
	int raw;

	modint() { raw = 0; }
	modint(int v) {
		if (v < 0) {
			raw = (v % M) + M;
		}
		else if (v >= M) {
			raw = v % M;
		}
		else {
			raw = v;
		}
	}
	modint operator + (modint v) const { return modint(raw) += v; }
	modint operator - (modint v) const { return modint(raw) -= v; }
	modint operator * (modint v) const { return modint(raw) *= v; }

	modint& operator += (modint v) {
		raw += v.raw;
		if (raw >= M) { raw -= M; }
		return *this;
	}
	modint& operator -= (modint v) {
		raw -= v.raw;
		if (raw < 0) { raw += M; }
		return *this;
	}
	modint& operator *= (modint v) {
		raw = (raw * v.raw) % M;
		return *this;
	}
	modint pow(int n) const {
		return modint::pow(raw, n);
	}
	static modint pow(int a, int n) {
		if (n < 0) {
			// not support
			abort();
		}

		int r = 1;
		while (n) {
			if (n & 1) {
				r = (r * a) % M;
			}
			a = (a * a) % M;
			n >>= 1;
		}
		return modint(r);
	}

	friend istream& operator>>(istream& is, modint& m) {
		int v;
		is >> v;
		m = modint(v);
		return is;
	}
	friend ostream& operator<<(ostream& os, modint const& m) {
		return os << m.raw;
	}
};

using mint = modint<MOD>;
using mints = arr<mint>;

//------------------------------------------------------------
#if defined(TEST)
extern istream& myInputStream;
extern ostream& myOutputStream;
#else
istream& myInputStream = cin;
ostream& myOutputStream = cout;
#endif

struct input {
	template <class A, class B>
	void exec(pair<A, B>& var) {
		myInputStream >> var.first >> var.second;
	}

	template <class T>
	void exec(T& var) {
		myInputStream >> var;
	}

	template <class T>
	operator T() {
		T var;
		exec(var);
		return var;
	}
} input;

struct inputs {
	ll n;
	inputs(ll n_) : n(n_) {}

	template <class T>
	operator arr<T>() {
		arr<T> var(n);
		REP(i, n) {
			var[i] = (T)input;
		};
		return var;
	}
};

struct inputss {
	int n;
	int m;
	inputss(int n_, int m_) : n(n_), m(m_) {}

	template <class T>
	operator arr<arr<T>>() {
		arr<arr<T>> var(n, arr<T>(m));
		REP(i, n) {
			REP(j, m) {
				var[i][j] = (T)input;
			}
		}
		return var;
	}
};

template <class T>
void output(T var) {
	myOutputStream << (var) << '\n';
}

//------------------------------------------------------------
#if defined(TEST)
#include "test.hpp"
#else
void myMain();
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);
	myMain();
	return 0;
}
#endif
#endif

//------------------------------------------------------------

void myMain() {
	int A = input;
	int B = input;
	int C = input;
	int X = input;
	int Y = input;

	int Z = min(X, Y);
	int value = min(A * Z + B * Z, C * Z * 2);
	X -= Z;
	Y -= Z;
	int value2 = min(A * X + B * Y, C * (X + Y) * 2);

	int ans = value + value2;

	output(ans);
}