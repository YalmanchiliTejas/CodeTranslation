#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define pb push_back
#define mp make_pair
#define fill(x, y) memset(x, y, sizeof(x))
#define even(x) x % 2 == 0
#define odd(x) x % 2 != 0
#define all(x) x.begin(), x.end()
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

// these functions return the position of result of Binary Search.
#define LB(s, t, x) (int) (lower_bound(s, t, x) - s)
#define UB(s, t, x) (int) (upper_bound(s, t, x) - s)

ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1) ans = 1ll * ans * a % mo; a = 1ll * a * a % mo; } while (b >>= 1); return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll temp = gcd(a, b); return temp ? (a / temp * b) : 0; }
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx8[] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dy8[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts>
auto make_v(size_t a, size_t b, Ts... ts) { return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...)); }
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }
// auto dp = make_v<int>(4, h, w);
// fill_v(dp, 0);

const ll INF_LL = (1ll << 60);
const int INF_INT = (int)1e9;
const ll MOD_CONST = (ll)(1e9 + 7);

template <class T>
bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

inline tuple<ll, ll> rotate45(tuple<ll, ll> point) { ll x = get<0>(point), y = get<1>(point); return tuple<ll, ll>(x + y, x - y); }
inline bool rangeCheck2D(int nx, int ny, int Width, int Height) { return nx >= 0 and nx < Width and ny >= 0 and ny < Height; }
void out_sequence(vector<ll> &out) { REP(i, (int)out.size()) { cout << out[i]; if (i == (int)out.size() - 1) cout << endl; else cout << " "; } }

ll dfs(vector<bool> &visited, vector<vector<int>> &g, int current, int cnt, int d) {
	visited[current] = true;
	ll ret = 0;
	bool needed = false;
	int nd = d;
	if (cnt == 2 or d) nd = 1;
	REP(i, g[current].size()) {
		int next = g[current][i];
		if (visited[next]) continue;
		int ncnt = cnt+1;
		if (not d and cnt == 2) ncnt = 1, needed = true;
		if (d and cnt == 1) ncnt = 1, needed = true;
		ret += dfs(visited, g, next, ncnt, nd);
	}
	if (needed) ret++;
	return ret;
}

int main(void)
{
	cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(20);

	ll H, W; cin >> H >> W;
	vector<string> f(H);
	REP(i, H) cin >> f[i];

	vector<bool> o(W);
	REP(i, W) {
		bool ok = true;
		REP(j, H) {
			if (f[j][i] == '#') {
				ok = false;
				break;
			}
		}
		if (ok) o[i] = true;
	}

	REP(i, H) {
		bool ok = true;
		REP(j, W) {
			if (f[i][j] == '#') {
				ok = false;
				break;
			}
		}
		if (ok) continue;
		REP(j, W) {
			if (o[j]) continue;
			cout << f[i][j];
		}
		cout << endl;
	}

	return 0;
}

//*/