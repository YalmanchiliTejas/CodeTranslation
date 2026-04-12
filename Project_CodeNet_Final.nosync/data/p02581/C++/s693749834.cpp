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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i].size(); j++)
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

template < typename A, size_t N, typename T >
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
struct initializer {
	initializer() {
		cout << fixed << setprecision(20);
	}
};
initializer _____;

int N, M, K, T, Q, H, W;
signed main() {
	cin >> N;
	vector< int > A(3 * N);
	rep(i, 3 * N) cin >> A[i];
	vector< vector< int > > dp(N + 1, vector< int >(N + 1, -LINF));
	int ans = 0;
	int tmp = 0;
	int maxdp = 0;
	dp[A[0]][A[1]] = 0;
	dp[A[1]][A[0]] = 0;
	vector< int > imax(N + 1, -LINF);
	vector< int > jmax(N + 1, -LINF);
	imax[A[0]] = 0;
	imax[A[1]] = 0;
	jmax[A[1]] = 0;
	jmax[A[0]] = 0;
	rep(i, N) {
		if (i < N - 1) {
			int a = i * 3 + 2;
			int b = a + 1, c = b + 1;
			if (A[a] == A[b] && A[b] == A[c]) {
				tmp++;
				continue;
			}
			int p = A[a], q = A[b], r = A[c];
			vector< int > ps(3);
			ps[0] = p;
			ps[1] = q;
			ps[2] = r;
			queue< pair< pii, int > > next;
			auto f = [&](int i, int j, int val) -> void {
				next.push(make_pair(pii(i, j), val));
			};
			f(q, r, dp[p][p] + 1);
			f(r, q, dp[p][p] + 1);
			f(r, p, dp[q][q] + 1);
			f(p, r, dp[q][q] + 1);
			f(p, q, dp[r][r] + 1);
			f(q, p, dp[r][r] + 1);
			if (p == q || q == r || r == p) {
				int y, z;
				if (p == q) {
					y = p, z = r;
				} else if (q == r) {
					y = q, z = p;
				} else {
					y = r, z = q;
				}
				for (int x = 1; x <= N; x++) {
					f(x, z, dp[x][y] + 1);
					f(x, z, dp[y][x] + 1);
					f(z, x, dp[y][x] + 1);
					f(z, x, dp[x][y] + 1);
				}
			}
			f(p, q, maxdp);
			f(q, p, maxdp);
			f(r, q, maxdp);
			f(q, r, maxdp);
			f(p, r, maxdp);
			f(r, p, maxdp);
			for (auto p : ps) {
				for (int l = 1; l <= N; l++) {
					f(p, l, jmax[l]);
					f(l, p, imax[l]);
				}
			}
			while (!next.empty()) {
				auto p = next.front();
				next.pop();
				int i = p.first.first;
				int j = p.first.second;
				int val = p.second;
				chmax(dp[i][j], val);
				chmax(maxdp, dp[i][j]);
				chmax(imax[i], dp[i][j]);
				chmax(jmax[j], dp[i][j]);
			}
		} else {
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++) {
					int tmp = dp[i][j];
					if (i == j && j == A.back()) {
						tmp++;
					}
					chmax(ans, tmp);
				}
		}
	}
	cout << ans + tmp << endl;

	return 0;
}