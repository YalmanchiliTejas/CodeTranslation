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
const int N = 10010 ;
const int K = 110 ;
const int INF = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const int MOD = 1000000007 ;
void print(int x) { cout << x << endl ; exit(0) ; }
void PRINT(string x) { cout << x << endl ; exit(0) ; }
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }

int dp[N][K][2] ;
char s[N] ;
int a[N] ;
int n, m ;

int dfs(int k, int now, int lim) {
//	cout << k << " " << now << " " << lim << endl ;
	if (dp[k][now][lim] >= 0) return dp[k][now][lim] ;
	if (k == m) return dp[k][now][lim] = (now == 0) ;
	int sum = 0, up = lim ? a[k] : 9 ;
//	cout << "in\n" << up << endl  ;
	for (int i = 0; i <= up; i++) {
//		cout << i << endl ;
		sum += dfs(k + 1, (now + i) % n, lim && i == up) ;
		if (sum >= MOD) sum -= MOD ;
	}
	return dp[k][now][lim] = sum ;
}

signed main(){
	scanf("%s%d", s, &n) ;
	m = strlen(s) ;
	for (int i = 0; i < m; i++) a[i] = s[i] - '0' ;
	ass(dp, -1) ;
	printf("%d\n", (dfs(0, 0, 1) + MOD - 1) % MOD) ; // 0 is incorrect
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
*/
