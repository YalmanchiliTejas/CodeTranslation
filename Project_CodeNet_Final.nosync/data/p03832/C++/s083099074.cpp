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
template < typename T, typename U >
ostream &operator<<(ostream &os, const pair< T, U > &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, d, c, i;
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
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll extgcd(ll a, ll b, ll &x, ll &y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1;
		y = 0;
	}
	return d;
}
ll factorial(ll x) {
	if (x == 1)
		return 1;
	else
		return x * factorial(x - 1);
}
ll Mfactorial(ll x, ll m) {
	ll ret = 1;
	for (ll i = 1; i <= x; i++) {
		ret *= i;
		ret %= m;
	}
	return ret;
}
vector< int > MfactTable(int n, int m) {
	vector< int > ret(n + 1);
	ret[0] = 1;
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		tmp *= i;
		tmp %= m;
		ret[i] = tmp;
	}
	return ret;
}
int Minverse(int a, int m) {
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
int McombSmall(int n, int k, int m) {
	//O(n)
	if (k > n)
		return 0;
	int ret = Mfactorial(n, m);
	ret *= Minverse(Mfactorial(k, m), m);
	ret %= m;
	ret *= Minverse(Mfactorial(n - k, m), m);
	return ret % m;
}
int McombFromFactTable(vector< int > &T, int n, int k, int m) {
	if (k > n)
		return 0;
	int ret = T[n];
	ret *= Minverse(T[k], m);
	ret %= m;
	ret *= Minverse(T[n - k], m);
	return ret % m;
}
ll pow(ll x, int n) {
	if (n == 0)
		return 1;
	ll ret = (n & 1) ? x : 1;
	ll a = pow(x, n / 2);
	return ret * a * a;
}
ll Mpow(ll x, int n, int m) {
	if (n == 0)
		return 1;
	ll ret = (n & 1) ? x : 1;
	ll a = Mpow(x, n / 2, m);
	return (((ret * a) % m) * a) % m;
}
vector< vector< int > > combTable(int N) {
	vector< vector< int > > ret(N + 1, vector< int >(N + 1));
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				ret[i][j] = 1;
			else
				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
		}
	return ret;
}
int countNmodPisQlr(int l, int r, int P, int Q) {
	//r>=l>=0
	return (r - Q + P) / P - (l - Q + P - 1) / P;
}
struct Combination {
	int N = 0, M;
	vector< int > Ftable, FItable, Inversetable;
	void init() {
		Ftable.resize(N + 1);
		FItable.resize(N + 1);
		Inversetable.resize(N + 1);
		Ftable[0] = 1;
		FItable[0] = 1;
		for (int i = 1; i <= N; i++)
			Ftable[i] = Ftable[i - 1] * i % M;
		FItable[N] = Minverse(Ftable[N], M);
		for (int i = N - 1; i >= 1; i--)
			FItable[i] = FItable[i + 1] * (i + 1) % M;
		Inversetable[1] = 1;
		for (int i = 2; i <= N; i++)
			Inversetable[i] = M - Inversetable[M % i] * (M / i) % M;
	}
	Combination(int max, int mod) {
		N = max;
		M = mod;
		init();
	}
	int calc(int n, int k) {
		if (k > n)
			return 0;
		int ret = Ftable[n] * FItable[k] % M * FItable[n - k] % M;
		return ret;
	}
	int inverse(int n) { return Inversetable[n]; }
	int factorial(int n) { return Ftable[n]; }
	int factorialInverse(int n) { return FItable[n]; }
	int permutation(int n, int k) {
		if (k > n)
			return 0;
		return Ftable[n] * FItable[n - k] % M;
	}
};
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N;
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	vector< vector< int > > dp(N + 1, vector< int >(N + 1, 0));
	Combination cmb(N + 10, MOD);
	dp[0][0] = 1;
	rep(i, N) {
		rep(j, N + 1) dp[i + 1][j] += dp[i][j];
		if (i + 1 < A)
			continue;
		rep(j, N) {
			for (int k = C; k <= min(D, (N - j) / (i + 1)); k++) {
				dp[i + 1][j + (i + 1) * k] += dp[i][j] * cmb.calc(N - j, (i + 1) * k) % MOD * cmb.factorial((i + 1) * k) % MOD * Mpow(cmb.factorialInverse(i + 1), k, MOD) % MOD * cmb.factorialInverse(k) % MOD;
				dp[i + 1][j + (i + 1) * k] %= MOD;
			}
		}
	}
	//cerr << dp;
	cout << dp[B][N] << endl;
	return 0;
}