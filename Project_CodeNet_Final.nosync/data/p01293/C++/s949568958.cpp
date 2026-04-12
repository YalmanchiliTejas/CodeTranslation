// template {{{

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) loop(i, 0, n)
#define rloop(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define rrep(i, n) rloop(i, 0, n)
#define pb push_back
#define pf push_front
#define eb emplace_back
#define ef emplace_front
#define all(c) std::begin(c), std::end(c)
#define mp std::make_pair
#define mt std::make_tuple
#define fi first
#define se second
#define popcnt __builtin_popcountll

using uint = std::uint32_t;
using ll = std::int64_t;
using ull = std::uint64_t;
using ld = long double;

template<typename T, size_t H, size_t W>
using matrix = std::array<std::array<T, W>, H>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ll LLINF = 1e18 + 10;

const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

template<typename T>
inline T sq(T x){ return x * x; }

template<typename T, typename U>
inline bool chmax(T &x, U y){ if (x >= y) return false; x = y; return true; }

template<typename T, typename U>
inline void chmin(T &x, U y){ if (x <= y) return false; x = y; return true; }

template<typename T>
inline void sort(T &c){ std::sort(all(c)); }

template<typename T>
inline void reverse(T &c){ std::reverse(all(c)); }

template<typename T>
inline void unique(T &c){ std::sort(c); c.erase(std::unique(all(c)), std::end(c)); }

// }}}

using pr = pair<int, int>;

int conv[256];

int main()
{
	rep(i, 4) conv["CHSD"[i]] = i;
	rep(i, 13) conv["23456789TJQKA"[i]] = i;

	string s;
	while (cin >> s, s != "#"){
		int t = conv[s[0]];
		pr c[13][4];
		int ns = 0, ew = 0;
		rep(i, 4) rep(j, 13){
			cin >> s;
			c[j][i] = pr(conv[s[1]], conv[s[0]]);
		}
		int d = 0;
		rep(i, 13){
			pr cmp[4][13];
			rep(j, 4) rep(k, 13){
				cmp[j][k] = pr(0, k);
				if (j == c[i][d].fi) cmp[j][k].fi = 1;
				else if (j == t) cmp[j][k].fi = 2;
			}
			pr mx(-1, -1);
			rep(j, 4){
				if (mx < cmp[c[i][j].fi][c[i][j].se]){
					mx = cmp[c[i][j].fi][c[i][j].se];
					d = j;
				}
			}
			(d & 1 ? ew : ns)++;
		}
		if (ns > ew) cout << "NS " << ns - 6 << endl;
		else cout << "EW " << ew - 6 << endl;
	}
}