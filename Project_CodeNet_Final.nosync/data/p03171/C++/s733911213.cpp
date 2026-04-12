#include <bits/stdc++.h>                                           
 
#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
using namespace std;
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;
typedef unsigned long long ull;         
typedef vector < pii > vpii;
typedef vector < int > vi;
typedef long double ldb; 
typedef long long ll;  
typedef double db;                         
 
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 555;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const int inf = 1e9, N = 3e3 + 48, mod = 1e9 + 7, maxn = 102;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;


int n, a[N], dp[N][N][2];

int rec (int l, int r, int tp) {
	if (l > r)	
		return 0;
	if (dp[l][r][tp] != -INF)
		return dp[l][r][tp];
	if (!tp)
		return dp[l][r][tp] = max(a[l] + rec(l + 1, r, tp ^ 1), a[r] + rec(l, r - 1, tp ^ 1));			         	
	return dp[l][r][tp] = min(-a[l] + rec(l + 1, r, tp ^ 1), -a[r] + rec(l, r - 1, tp ^ 1));			
}


main () {
	cin >> n;
	forn (i, 1, n)
		cin >> a[i];

	forn (i, 1, n)
		forn (j, 1, n)
			forn (tp, 0, 1)
				dp[i][j][tp] = -INF;

	cout << rec(1, n, 0);
}                       