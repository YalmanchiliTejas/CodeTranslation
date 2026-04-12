#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <string>
#include <numeric>
#include <cstring>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std ;
#define rep(i, a, b) for (register ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (register ll i = (a); i >= (b); --i)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (register int i = head[x]; i; i = edge[i].nex)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, cnt) memset(a, cnt, sizeof(a))
#define cop(a, b) memcpy(a, b, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define SC(t, x) static_cast <t> (x)
#define ub upper_bound
#define lb lower_bound
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define y1 y1_
#define Pi acos(-1.0)
#define iv inline void
#define enter putchar('\n')
#define siz(x) ((int)x.size())
#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)
typedef double db ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <int, int> pii ;
typedef vector <int> vi ;
typedef vector <pii> vii ;
typedef queue <int> qi ;
typedef queue <pii> qii ;
typedef set <int> si ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int maxn = 1e2 + 5 ;
const int inf = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const ll mod = 1e9 + 7 ;
const double eps = 1e-7 ;
template <class T = int> T read()
{
	T f = 1, a = 0;
	char ch = getchar() ;
	while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
	while (isdigit(ch)) { a =  (a << 3) + (a << 1) + ch - '0' ; ch = getchar() ; }
	return a * f ;
}

ll power(ll a, ll b)
{
	ll ret = 1;
	for(; b; b >>= 1, (a *= a) %= mod) if(b & 1) (ret *= a) %= mod;
	return ret;
}

ll n, ans;

ll h[maxn];

ll f[maxn][maxn], g[maxn][maxn];

void solve(ll l, ll r, ll d)
{
	// printf("%lld %lld\n", l, r);
	if(l > r) return ;
	ll pos, maxx = linf;
	rep(i, l, r) if(h[i] < maxx) maxx = h[i], pos = i;
	g[l][r] += h[pos] - d;
	solve(l, pos - 1, h[pos]), solve(pos + 1, r, h[pos]);
}

signed main()
{
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &h[i]);
	solve(1, n, 1);
	// rep(i, 1, n) rep(j, i, n) printf("%lld %lld : %lld\n", i, j, g[i][j]);
	rep(i, 1, n) per(j, i - 1, 1) (g[j][i] += g[j + 1][i]) %= (mod - 1);
	// rep(i, 1, n) rep(j, i, n) printf("%lld %lld : %lld\n", i, j, g[i][j]);
	f[1][1] = (2 * power(2, g[1][1])) % mod;
	rep(i, 1, n - 1) rep(j, 1, i)
	{
		(f[i + 1][j + 1] += f[i][j] * power(2, g[i - j + 1][i + 1]) % mod) %= mod;
		(f[i + 1][1] += f[i][j] * power(2, g[i + 1][i + 1]) % mod) %= mod;
	}
	rep(i, 1, n) (ans += f[n][i]) %= mod;
	printf("%lld\n", ans);
	return 0;
}