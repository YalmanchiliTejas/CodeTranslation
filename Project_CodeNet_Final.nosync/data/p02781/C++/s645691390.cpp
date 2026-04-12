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

int N, M, K, T, Q, H, W;
signed main() {
	string N;
	cin >> N >> K;
	M = N.size();
	vector< int > A(M);
	rep(i, M) A[i] = N[i] - '0';
	vector< int > level(M);
	level[0] = 0;
	for (int i = 1; i < M; i++) {
		level[i] = level[i - 1];
		if (A[i] > 0)
			level[i]++;
	}
	int ans = 0;
	rep(i, M) {
		if (K >= 2) {
			rep(j, M) {
				if (K >= 3) {
					rep(k, M) if (i < j && j < k) {
						if (i == 0 && level[i] == level[j - 1] && level[j] == level[k - 1])
							ans += (A[j] > 0 ? A[k] : 0) + (A[j] > 0 ? ((A[j] - 1) * 9) : 0) + (A[i] - 1) * 9 * 9;
						else if (i == 0 && level[i] == level[j - 1]) {
							ans += A[j] * 9 + (A[i] - 1) * 9 * 9;
						} else if (i == 0)
							ans += A[i] * 9 * 9;
						else
							ans += 9 * 9 * 9;
					}
				} else {
					if (i >= j)
						continue;
					if (i == 0 && level[i] == level[j - 1]) {
						ans += A[j] + (A[i] - 1) * 9;
					} else {
						if (i == 0) {
							ans += A[i] * 9;
						} else {
							ans += 9 * 9;
						}
					}
				}
			}
		} else {
			if (i == 0)
				ans += A[i];
			else
				ans += 9;
		}
	}
	cout << ans << endl;
	return 0;
}