//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000
#define MAXM 200000

#define MOD 1000000007

//#include "graph/dijkstra_g.h"
template<class T>
int weight_relax(T &best, const T &cur, const T &add) {
	T w = cur + add;
	if (w < best) {
		best = cur + add;
		return 1;
	}
	else if (w==best) return 0;
	else return -1;
}

template<class graph, class T>
void dijkstra_g(graph &g, int source, T *dist) {
	typedef pair<T,int> node;
	priority_queue<node, vector<node>, greater<node>> q;

	int n = g.size();
	for (int i=0; i<n; i++)
		dist[i] = numeric_limits<T>::max();

	dist[source] = T();
	q.push({dist[source], source});

	while (!q.empty()) {
		node x = q.top();
		q.pop();
		int u = x.second;
		if (dist[u] < x.first)
			continue;
		for (auto &y: g[u]) {
			int v = y.first;
			if (weight_relax(dist[v], dist[u], y.second)>0)
				q.push({dist[v], v});
		}
	}
}
//#include "graph/weight.h"
template<class W, class N>
struct path_cnt {
	W d;
	N n;
	path_cnt(W d=0):d(d),n(1) {};
	bool operator<(const path_cnt &o) const {
		return d < o.d;
	}

	friend int weight_relax(path_cnt &best, const path_cnt &cur, const path_cnt &add) {
		int r = weight_relax(best.d, cur.d, add.d);
		if (r>0) best.n = cur.n;
		else if (r==0) best.n = best.n + cur.n;
		return r;
	}

};

namespace std {
	template<class W, class N>
	class numeric_limits<path_cnt<W,N>> {
	public:
		static path_cnt<W,N> max() {
			return numeric_limits<W>::max();
		}
	};
}

#include <iostream>
template<class W, class N>
ostream &operator<<(ostream &os, const path_cnt<W,N> &x) {
		return os << '{' << x.d << ',' << x.n << '}';
	}
//#include "math/modulo.h"
//#include "math/func.h"

template<class T>
T pow(const T &x, long n) {
	T y(1);
	while (n) {
		if (n%2) y = y * x;
		n /= 2;
		x = x * x;
	}
	return y;
}

template<class T>
T fac(long n) {
	T y(1);
	for (long i=2; i<n; i++)
		y = y * T(i);
	return y;
}

template<class T>
T gcd(const T &a, const T &b) {
	return a==0 ? b: gcd(b%a, b);
}

template<class T>
T gcd_ext(const T &a, const T &b, T *x, T *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	T x1, y1;
	T g = gcd_ext(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return g;
}


template<class T, T M>
struct modulo {
	T n;
	modulo(T n): n(n<0? n%M+M: n%M)   { }
	operator T() const                { return n;             }
	modulo operator-() const          { return modulo(-n);    }
	modulo operator+(const modulo &o) const { return modulo(n+o.n); }
	modulo operator-(const modulo &o) const { return modulo(n-o.n); }
	modulo operator*(const modulo &o) const { return modulo(n*o.n); }
	bool  operator< (const modulo &o) const { return n< o.n; }
	bool  operator<=(const modulo &o) const { return n<=o.n; }
	bool  operator> (const modulo &o) const { return n> o.n; }
	bool  operator>=(const modulo &o) const { return n>=o.n; }
	bool  operator==(const modulo &o) const { return n==o.n; }
	bool  operator!=(const modulo &o) const { return n!=o.n; }

	modulo pow(T n) const {
		return ::pow(*this, n);
	}
	modulo inv() const {
		return pow(M-2);
	}
	modulo operator/(const modulo &o) const {
		return (*this) * o.inv();
	}

	modulo div(const modulo &o) const {
		T x, y;
		T g = gcd_ext(o.n, M, &x, &y);
		if (g != 1) return 0;
		else return modulo(n * (x % M));
	}

	friend ostream &operator<<(ostream &os, const modulo &x) {
		return os << x.n;
	}
};


typedef modulo<long,MOD> T;
typedef path_cnt<long,T> W;
vector<vector<pair<int,W>>> g;

int n, m;
int s, t;

int input() {
	if (scanf("%d %d", &n, &m) < 0) return 0;
	g.resize(n);
	scanf("%d %d", &s, &t);
	s--, t--;
	for (int i=0; i<m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		x--, y--;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	return 1;
}

void init() {
}

W ds[MAXN], dt[MAXN];

long solve() {
	dijkstra_g(g, s, ds);
	dijkstra_g(g, t, dt);
	//printa(ds, n); printa(dt, n);

	long len = ds[t].d;
	T r = ds[t].n * dt[s].n;
	for (int i=0; i<n; i++)	{
		if (ds[i].d==dt[i].d && ds[i].d*2==len) {
			T x = ds[i].n * dt[i].n;
			r = r - x*x;
		}
	}
	for (int i=0; i<n; i++) {
		for (auto e: g[i]) {
			int j = e.first;
			if (ds[i].d + dt[j].d + e.second.d != len) continue;
			if (ds[i].d*2 < len && dt[j].d*2 < len) {
				T x = ds[i].n * dt[j].n;
				r = r - x*x;
			}
		}
	}
	return r;
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
	g.clear();
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



