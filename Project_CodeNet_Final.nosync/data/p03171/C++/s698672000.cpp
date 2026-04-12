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
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, sum) memset(a, sum, sizeof(a))
#define lowbit(x) (x & -x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define enter cout << endl
#define siz(x) ((int)x.size())
typedef long long ll ;
typedef unsigned long long ull ;
typedef vector <int> vi ;
typedef pair <int, int> pii ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int N = 3010 ;
const int INF = 0x3f3f3f3f ;
const int iinf = INF ;
const ll linf = 1e15 ;
const int MOD = 1000000007 ;
void print(int x) { cout << x << endl ; exit(0) ; }
void PRINT(string x) { cout << x << endl ; exit(0) ; }
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }

ll dp[N][N] ;
ll a[N] ;
int n ;

signed main() {
	scanf("%d", &n) ;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]) ;
	for (int i = 1; i <= n; i++) dp[i][i] = a[i] ;
	for (int i = 2; i <= n; i++)
	for (int j = 1; i + j - 1 <= n; j++)
	dp[j][i + j - 1] = max(a[j] - dp[j + 1][i + j - 1], -dp[j][i + j - 2] + a[i + j - 1]) ;
	printf("%lld\n", dp[1][n]) ;
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
*/
