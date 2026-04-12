// template {{{

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) loop(i, 0, n)
#define rloop(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define rrep(i, n) rloop(i, 0, n)
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define pf pop_front
#define all(c) std::begin(c), std::end(c)
#define mp std::make_pair
#define mt std::make_tuple
#define fi first
#define se second
#define popcnt __builtin_popcountll

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;
using tp = tuple<int, int, int>;
using tp4 = tuple<int, int, int, int>;
using tp5 = tuple<int, int, int, int, int>;

template<typename T>
using max_pq = priority_queue<T, vector<T>, less<T>>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ll LLINF = 1e18 + 10;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<typename T>
inline T sq(T x){ return x * x; }

template<typename T, typename U>
inline bool chmax(T &x, U y){ if (x >= y) return false; x = y; return true; }

template<typename T, typename U>
inline bool chmin(T &x, U y){ if (x <= y) return false; x = y; return true; }

template<typename T>
inline void sort(T &c){ std::sort(std::begin(c), std::end(c)); }

template<typename T>
inline void reverse(T &c){ std::reverse(std::begin(c), std::end(c)); }

template<typename T>
inline void unique(T &c){ std::sort(std::begin(c), std::end(c)); c.erase(std::unique(all(c)), std::end(c)); }

// }}}

const int t[] = {0, 60, 70, 80};
bool f[5][5];
int a[5][5];
int dp[17][65536];

int calc(int p, int st)
{
	if (~dp[p][st]) return dp[p][st];
	if (p == 16) return 0;
	
	int res = 0;
	int ds = 0;
	int x = p / 4, y = p % 4;
	rep(i, 4){
		chmax(res, ds + calc(p + 1, (st * 4 + i) % 65536));
		rep(dx, 2) rep(dy, 2){
			if (f[x + dx][y + dy]){
				ds -= t[a[x + dx][y + dy]];
				++a[x + dx][y + dy] %= 4;
				ds += t[a[x + dx][y + dy]];
			}
		}
	}

	return dp[p][st] = res;
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--){
		rep(i, 5) rep(j, 5) scanf("%d", &a[i][j]), a[i][j]--;
		rep(i, 5) rep(j, 5) f[i][j] = a[i][j] >= 0;
		int sum = 0;
		rep(i, 5) rep(j, 5){
			if (f[i][j]) sum += t[a[i][j]];
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", sum + calc(0, 0));
	}
}