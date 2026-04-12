// Hacheylight
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
//#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, sum) memset(a, sum, sizeof(a))
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
#define enter cout << endl
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
const int N = 110 ;
const int INF = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const int MOD = 1000000007 ;
const double eps = 1e-7 ;
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }
template <class T> void print(T a) { cout << a << endl ; exit(0) ; }
template <class T> void chmin(T &a, T b) { if (a > b) a = b ; }
template <class T> void chmax(T &a, T b) { if (a < b) a = b ; }
template <class T> void add(T &a, T b) { a = (1ll * a + b) % MOD ; }
template <class T> void sub(T &a, T b) { a = (a - b + MOD) % MOD ; }
template <class T> void mul(T &a, T b) { a = (ll) a * b % MOD ; }
template <class T> T read() {
    int f = 1 ; T x = 0 ;
    char ch = getchar() ;
    while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
    while (isdigit(ch)) { x = x * 10 + ch -'0' ; ch = getchar() ; }
    return x * f ;
}


int pw(int a, int b) {
	int s = 1 ;
	for (; b; b >>= 1, a = (ll) a * a % MOD)
	if (b & 1) s = (ll) s * a % MOD ;
	return s ;
}

int n ;
int h[N] ;

pii solve(int l, int r, int lim) {
	int mi = iinf, cnt = 0 ; pii ans ;
	rep(i, l, r) if (h[i] < mi) mi = h[i], cnt = 1 ;
	else if (h[i] == mi) cnt++ ;
	if (cnt == r - l + 1) {
		ans.fi = (pw(2, r - l + 1) - 2 + MOD) % MOD ;
		ans.se = pw(2, mi - lim - 1) ;
		return ans ;
	}
	int rst = r - l + 1, s0 = 1, s1 = 1, lst = 0 ;
	rep(i, l, r + 1)
	if (!lst && h[i] > mi) lst = i ;
	else if (lst && (h[i] <= mi || i > r)) {
		rst -= i - lst ;
		pii tmp = solve(lst, i - 1, mi) ;
		mul(s0, (int) (tmp.first + 4ll * tmp.se % MOD) % MOD) ;
		mul(s1, (int) (2ll * tmp.se % MOD) % MOD) ;
		lst = 0 ;
	}
	sub(s0, s1) ;
	ans.fi = (ll) s0 * pw(2, rst) % MOD ;
	add(ans.fi, (int) ((ll) s1 * (pw(2, rst) % MOD - 2 + MOD) % MOD) % MOD) ;
	ans.se = (ll) s1 * pw(2, mi - lim - 1) % MOD ;
	return ans ;
}


signed main() {
	scanf("%d", &n) ;
	rep(i, 1, n) scanf("%d", &h[i]) ;
	if (n == 1) print(pw(2, h[1])) ;
	int peak = 1 ;
	rep(i, 1, n)
	if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
		mul(peak, pw(2, h[i] - max(h[i - 1], h[i + 1]))) ;
		h[i] = max(h[i - 1], h[i + 1]) ;
	}
	pii ans = solve(1, n, 0) ;
	printf("%lld\n", (ll) peak * (ans.fi + 2ll * ans.se % MOD) % MOD) ;

	return 0 ;
}

/*
写代码时请注意：
	1.ll？数组大小，边界？数据范围？
	2.精度？
	3.特判？
	4.至少做一些
思考提醒：
	1.最大值最小->二分？
	2.可以贪心么？不行dp可以么
	3.可以优化么
	4.维护区间用什么数据结构？
	5.统计方案是用dp？模了么？
	6.逆向思维？
*/



