#include "bits/stdc++.h"
using namespace std;

#define say(obj) (cout << (obj) << endl)
#define endline (cout << endl)
#define all(container) (container).begin(), (container).end()
#define sortall(container) (sort((container).begin(), (container).end()))
#define yn(cond) ((cond) ? (cout << "yes" << endl) : (cout << "no" << endl))
#define Yn(cond) ((cond) ? (cout << "Yes" << endl) : (cout << "No" << endl))
#define YN(cond) ((cond) ? (cout << "YES" << endl) : (cout << "NO" << endl))

typedef long long       ll;

typedef vector<int>     vi;
typedef vector<ll>      vll;
typedef vector<double>  vd;
typedef vector<bool>    vb;
typedef vector<char>    vc;
typedef vector<string>  vs;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvll;
typedef vector<vd>		vvd;
typedef vector<vb>		vvb;
typedef vector<vc>		vvc;
typedef vector<vs>		vvs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;

typedef struct edge_ {
	ll to, cost;
	edge_(ll to, ll cost) : to(to), cost(cost) {}
} edge;

typedef struct point_ {
	ll x, y;
	point_(ll x = 0, ll y = 0) : x(x), y(y) {}
} point;

template <typename T>
using mat2d = vector<vector<T>>;

constexpr double	PI = 3.14159265358979323846;
constexpr int		INF = (int)1e7;
constexpr ll		MOD = (ll)1e9 + 7;
constexpr double	EPS = 1e-7;
constexpr int		dy4[4] = { 0, 1, 0, -1 };
constexpr int		dx4[4] = { 1, 0, -1, 0 };
constexpr int		dy8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
constexpr int		dx8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

template <typename T>
T getSum(std::vector<T>& v) {
	T ret = 0;
	for (T& x : v) ret += x;
	return ret;
}

template <typename T>
istream& operator >> (istream& is, vector<T>& vec) { for (T& x : vec) is >> x;  return is; }
template <typename S, typename T>
istream& operator >> (istream& is, pair<S, T>& p) { is >> p.first >> p.second; return is; }
istream& operator >> (istream& is, point& p) { is >> p.x >> p.y;          return is; }

template <typename T>
ostream& operator << (ostream& os, const vector<T>& vec) { for (const T& x : vec) os << x << " "; return os; }
template <typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& mat) { for (const vector<T>& m : mat) os << m << endl; return os; }
template <typename S, typename T>
ostream& operator << (ostream& os, const pair<S, T>& p) { os << "{" << p.first << " : " << p.second << "}"; return os; }
template <typename T>
ostream& operator << (ostream& os, const set<T>& s) { for (const T& x : s) os << x << " "; return os; }
ostream& operator << (ostream& os, const edge e) { os << "{to: " << e.to << ", cost: " << e.cost << "}"; return os; }
ostream& operator << (ostream& os, const point& p) { os << "(" << p.x << " " << p.y << ")"; return os; }

/******************************************************************************/
/**********************         Don't make WA !!         **********************/
/******************************************************************************/

int main()
{
	int N;
	cin >> N;
	vi H(N);
	cin >> H;

	int ans = 1;
	int ma = H[0];
	for (int i = 1; i < N; i++) {
		if (ma <= H[i])
			ans++;

		ma = max(ma, H[i]);
	}

	say(ans);

	return 0;
}