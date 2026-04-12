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
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define loop(s, v, it) for (s::iterator it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, sum) memset(a, sum, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define iv inline void
#define enter cout << endl
#define siz(x) ((int)x.size())
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <int, int> pii ;
typedef vector <int> vi ;
typedef vector <pii> vii ;
typedef set <int> si ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int N = 200010 ;
const int INF = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const int MOD = 1000000007 ;
void print(int x) { cout << x << endl ; exit(0) ; }
void PRINT(string x) { cout << x << endl ; exit(0) ; }
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }

int n, m ;
vii p[N] ;
ll tr[N << 2], tag[N << 2] ;

void modify(int v, int s, int t, int l, int r, ll x) {
	if (s >= l && t <= r) {
		tr[v] += x ;
		tag[v] += x ;
		return ;
	}
	int mid = (s + t) >> 1 ;
	if (l <= mid) modify(v << 1, s, mid, l, r, x) ;
	if (r > mid) modify(v << 1 | 1, mid + 1, t, l, r, x) ;
	tr[v] = max(tr[v << 1], tr[v << 1 | 1]) + tag[v] ;
}

signed main(){
	scanf("%d%d", &n, &m) ;
	rep(i, 1, m) {
		int l, r, c ; scanf("%d%d%d", &l, &r, &c) ;
		p[r].pb(mp(l, c)) ;
 	}
	rep(i, 1, n) {
		modify(1, 1, n, i, i, tr[1]) ;
		rep(j, 0, siz(p[i]) - 1) {
			pii q = p[i][j] ;
			modify(1, 1, n, q.fi, i, q.se) ;
		}
	}
	printf("%lld\n", max(tr[1], 0ll)) ;

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
