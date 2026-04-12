#include <bits/stdc++.h>                                           
 
//#define int long long
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
const int inf = 1e9, N = 1e4 + 48, mod = 1e9 + 7, maxn = 102;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;


string s;
int d, dp[N][maxn][2];


void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}       

int rec (int i, int rest, int ok) {
   	if (i == sz(s)) {
   		if (!rest)
   			return 1;
   		return 0;
   	}
   		
    int &res = dp[i][rest][ok];
	if (res != -1)
		return res;

	res = 0;
	if (ok) {
		forn (x, 0, s[i] - '0' - 1)	
			add(res, rec(i + 1, (rest + x) % d, 0));
		add(res, rec(i + 1, (rest + s[i] - '0') % d, 1));			
	} else {
		forn (x, 0, 9)
			add(res, rec(i + 1, (rest + x) % d, 0));
	}
	return res;
}


main () {
	memset(dp, -1, sizeof(dp));
	cin >> s >> d;
	cout << (rec(0, 0, 1) + mod - 1) % mod << endl;	
} 