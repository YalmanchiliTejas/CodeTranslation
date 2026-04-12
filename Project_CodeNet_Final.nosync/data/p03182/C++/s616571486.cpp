#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
#define MOD2 998244353
#define int long long
#define double long double
#define EPS 1e-9
//#define PI 3.14159265358979

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

template < typename T >
ostream &operator<<(ostream &os, const vector< T > &A) {
	for (int i = 0; i < A.size(); i++)
		os << A[i] << " ";
	os << endl;
	return os;
}
template <>
ostream &operator<<(ostream &os, const vector< vector< int > > &A) {
	int N = A.size();
	int M;
	if (N > 0)
		M = A[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			os << A[i][j] << " ";
		os << endl;
	}
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, d, c;
	edge(int _from = 0, int _to = 0, int _d = 0, int _c = 0) {
		from = _from;
		to = _to;
		d = _d;
		c = _c;
	}
	bool operator<(const edge &rhs) const {
		return (d == rhs.d) ? (c < rhs.c) : (d < rhs.d);
	}
};
struct aabb {
	int x1, y1, x2, y2;
	aabb(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

typedef vector< edge > edges;
typedef vector< edges > graph;
struct flow {
	int to, cap, rev, cost;
	flow(int to = 0, int cap = 0, int rev = 0, int cost = 0) : to(to), cap(cap), rev(rev), cost(cost) {}
};
typedef vector< vector< flow > > flows;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {-1, 0, 1, 0};
const int ci[5] = {0, 0, -1, 0, 1};
const int cj[5] = {0, -1, 0, 1, 0};
const ll LINF = LLONG_MAX / 2;
const int INF = INT_MAX / 2;
const double PI = acos(-1);

int pow2(int n) { return 1LL << n; }
template < typename T, typename U >
bool chmin(T &x, const U &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
template < typename T, typename U >
bool chmax(T &x, const U &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

struct initializer {
	initializer() {
		cout << fixed << setprecision(20);
	}
};
initializer _____;
struct LSegT {
	int N;
	vector< int > node, lazy;
	LSegT(vector< int > &A) {
		int sz = A.size();
		N = 1;
		while (N < sz)
			N *= 2;
		node.resize(2 * N - 1);
		lazy.resize(2 * N - 1, 0);
		rep(i, sz) node[i + N - 1] = A[i];
		for (int i = N - 2; i >= 0; i--)
			node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != 0) {
			node[k] += lazy[k];
			if (r - l > 1) {
				lazy[2 * k + 1] += lazy[k];
				lazy[2 * k + 2] += lazy[k];
			}
			lazy[k] = 0;
		}
	}
	void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
		if (r < 0)
			r = N;
		eval(k, l, r);
		if (b <= l || r <= a)
			return;
		if (a <= l && r <= b) {
			lazy[k] += x;
			eval(k, l, r);
		} else {
			add(a, b, x, 2 * k + 1, l, (l + r) / 2);
			add(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = max(node[2 * k + 1], node[2 * k + 2]);
		}
	}
	int sum(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)
			r = N;
		if (b <= l || r <= a)
			return -LINF;
		eval(k, l, r);
		if (a <= l && r <= b)
			return node[k];
		int vl = sum(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = sum(a, b, 2 * k + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
};
struct range {
	int l, r, c;
	range(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c) {}
	bool operator<(const range &rhs) const {
		return l < rhs.l;
	}
};
struct event {
	int x, y, a;
};
bool operator<(const event &lhs, const event &rhs) {
	return lhs.x < rhs.x;
}
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N >> M;
	vector< event > E(M * 2);
	rep(i, M) {
		int l, r, a;
		cin >> l >> r >> a;
		//--l;
		//--r;
		E[i * 2].x = l;
		E[i * 2].y = l;
		E[i * 2].a = a;
		E[i * 2 + 1].x = r + 1;
		E[i * 2 + 1].y = l;
		E[i * 2 + 1].a = -a;
	}
	sort(E.begin(), E.end());
	//rep(i, 2 * M) cout << E[i].x << " " << E[i].y << " " << E[i].a << endl;
	vector< int > dp(N + 1, 0);
	vector< int > A(N, 0);
	LSegT lsgt(dp);
	int ans = 0;
	int j = 0;
	rep(i, N) {
		while (j < M * 2 && E[j].x <= i + 1) {
			lsgt.add(0, E[j].y, E[j].a);
			//	cout << E[j].y << " ";
			//	cout << endl;
			j++;
			//cout << i << " " << j << endl;
		}
		//	rep(k, N + 1) cout << lsgt.sum(k, k + 1) << " ";
		//cout << endl;
		lsgt.add(i + 1, i + 2, lsgt.sum(0, i + 1));
		chmax(ans, lsgt.sum(0, N + 1));
	}
	cout << ans << endl;
	LSegT tmp(A);
	tmp.add(0, 2, 1);
	tmp.add(1, 3, 1);
	//rep(i, N) cout << tmp.sum(i, i + 1) << " ";
	//cout << endl;
	return 0;
}