//C

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
//#define int long long
//#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define INF 9223372036854775807 / 2
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair


using namespace std;

std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

struct uf_tree {
	std::vector<int> parent;
	int __size;
	uf_tree(int size_) : parent(size_, -1), __size(size_) {}
	void unite(int x, int y) {
		if ((x = find(x)) != (y = find(y))) {
			if (parent[y] < parent[x]) std::swap(x, y);
			parent[x] += parent[y];
			parent[y] = x;
			__size--;
		}
	}
	bool is_same(int x, int y) { return find(x) == find(y); }
	int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
	int size(int x) { return -parent[find(x)]; }
	int size() { return __size; }
};



//!!!問題をちゃんと読む!!!
//!!!問題をちゃんと読め!!!
//!!!問題は読みましたか？!!!

template <signed M, unsigned T>
struct mod_int {
	constexpr static signed MODULO = M;
	constexpr static unsigned TABLE_SIZE = T;

	signed x;

	mod_int() : x(0) {}

	mod_int(long long y) : x(static_cast<signed>(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO)) {}

	mod_int(int y) : x(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO) {}

	mod_int &operator+=(const mod_int &rhs) {
		if ((x += rhs.x) >= MODULO) x -= MODULO;
		return *this;
	}

	mod_int &operator-=(const mod_int &rhs) {
		if ((x += MODULO - rhs.x) >= MODULO) x -= MODULO;
		return *this;
	}

	mod_int &operator*=(const mod_int &rhs) {
		x = static_cast<signed>(1LL * x * rhs.x % MODULO);
		return *this;
	}

	mod_int &operator/=(const mod_int &rhs) {
		x = static_cast<signed>((1LL * x * rhs.inv().x) % MODULO);
		return *this;
	}

	mod_int operator-() const { return mod_int(-x); }

	mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }

	mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }

	mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }

	mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }

	bool operator<(const mod_int &rhs) const { return x < rhs.x; }

	mod_int inv() const {
		assert(x != 0);
		if (x <= static_cast<signed>(TABLE_SIZE)) {
			if (_inv[1].x == 0) prepare();
			return _inv[x];
		}
		else {
			signed a = x, b = MODULO, u = 1, v = 0, t;
			while (b) {
				t = a / b;
				a -= t * b;
				std::swap(a, b);
				u -= t * v;
				std::swap(u, v);
			}
			return mod_int(u);
		}
	}

	mod_int pow(long long t) const {
		assert(!(x == 0 && t == 0));
		mod_int e = *this, res = mod_int(1);
		for (; t; e *= e, t >>= 1)
			if (t & 1) res *= e;
		return res;
	}

	mod_int fact() {
		if (_fact[0].x == 0) prepare();
		return _fact[x];
	}

	mod_int inv_fact() {
		if (_fact[0].x == 0) prepare();
		return _inv_fact[x];
	}

	mod_int choose(mod_int y) {
		assert(y.x <= x);
		return this->fact() * y.inv_fact() * mod_int(x - y.x).inv_fact();
	}

	static mod_int _inv[TABLE_SIZE + 1];

	static mod_int _fact[TABLE_SIZE + 1];

	static mod_int _inv_fact[TABLE_SIZE + 1];

	static void prepare() {
		_inv[1] = 1;
		for (int i = 2; i <= (int)TABLE_SIZE; ++i) {
			_inv[i] = 1LL * _inv[MODULO % i].x * (MODULO - MODULO / i) % MODULO;
		}
		_fact[0] = 1;
		for (unsigned i = 1; i <= TABLE_SIZE; ++i) {
			_fact[i] = _fact[i - 1] * int(i);
		}
		_inv_fact[TABLE_SIZE] = _fact[TABLE_SIZE].inv();
		for (int i = (int)TABLE_SIZE - 1; i >= 0; --i) {
			_inv_fact[i] = _inv_fact[i + 1] * (i + 1);
		}
	}
};

template <int M, unsigned F>
std::ostream &operator<<(std::ostream &os, const mod_int<M, F> &rhs) {
	return os << rhs.x;
}

template <int M, unsigned F>
std::istream &operator>>(std::istream &is, mod_int<M, F> &rhs) {
	long long s;
	is >> s;
	rhs = mod_int<M, F>(s);
	return is;
}

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv[TABLE_SIZE + 1];

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
bool operator==(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
	return lhs.x == rhs.x;
}

template <int M, unsigned F>
bool operator!=(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
	return !(lhs == rhs);
}

const int MF = 1000010;
const int MOD = 1000000007;

using mint = mod_int<MOD, MF>;

mint binom(int n, int r) { return (r < 0 || r > n || n < 0) ? 0 : mint(n).choose(r); }

mint fact(int n) { return mint(n).fact(); }

mint inv_fact(int n) { return mint(n).inv_fact(); }

mint Sum(mint first, mint last) {
	return (last + first) * (last - first + 1) / 2;
}

signed main() {
	int inN, inM, inK;
	cin >> inN >> inM >> inK;

	mint N(inN), M(inM), K(inK);

	mint ans(0);

	int H = inN, W = inM;

	rep(i, H) {
		rep(j, W) {
			
			mint add(0);
			//注目してるマスのある行の左 + 右
			mint rowMin = Sum(0, j) + Sum(0, W - j - 1);
			add += rowMin * H;
			mint allCol = (Sum(0, i) + Sum(0, H - i - 1))*W;
			add += allCol;

			add *= binom(inN*inM - 2, inK - 2);
			ans += add;
		}
	}

	cout << ans / 2 << "\n";
	return 0;
}