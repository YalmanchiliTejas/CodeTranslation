#include <bits/stdc++.h>                                           
 
#define int unsigned long long
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
 
 
//const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 555;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const int inf = 1e9, maxn = 4e5 + 148, mod = 1e9 + 7, N = 511;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;



int n, s[N], t[N], u[N], v[N], p = 1, c[N][N], a[N], b[N], res[N][N];
bool used[N];


void Exit () {
	cout << -1;
	exit(0);
}


void solve () {
	memset(c, -1, sizeof(c));	
	memset(used, 0, sizeof(used));

	for (int i = 1; i <= n; ++i) {
		 a[i] = u[i] % 2;
		 b[i] = v[i] % 2;
	}
	

	vi ox, oy, ax, ay;

	for (int i = 1; i <= n; ++i)
		if (!s[i] && a[i]) {
			for (int j = 1; j <= n; ++j)
				c[i][j] = 1;
		} else if (s[i] && !a[i]) {
			for (int j = 1; j <= n; ++j)    
				c[i][j] = 0;
		} else if (!s[i])
			ax.pb(i);
		else
			ox.pb(i);

	for (int i = 1; i <= n; ++i)
		if (!t[i] && b[i]) {
			for (int j = 1; j <= n; ++j) {
			    if (!c[j][i]) 
			    	Exit();
				c[j][i] = 1; 
			}
		} else if (t[i] && !b[i]) {
			for (int j = 1; j <= n; ++j) {
			    if (c[j][i] == 1)
			    	Exit();
				c[j][i] = 0;               
			}
		} else if (!t[i])
			ay.pb(i);
		else
			oy.pb(i);


	for (auto x : ox) {
		bool found = 0;
		for (int y = 1; y <= n; ++y) {
			if (c[x][y] == 1) {
				found = 1;
				break;
			}
			if (t[y] && b[y]) {
				c[x][y] = 1;
				found = 1;
				break;				        
			}
		}

		if (found)
			continue;
		for (int y = 1; y <= n; ++y) {
			if (c[x][y] == -1 && !used[y]) {
				c[x][y] = 1;
				used[y] = 1;
				found = 1;
				break;
			}				
		}
		if (found)
			continue;

		for (int y = 1; y <= n; ++y) {
			if (c[x][y] == -1) {
				c[x][y] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
			Exit();
	}
	
	memset(used, 0, sizeof(used));

	for (auto y : oy) {
		bool found = 0;
		for (int x = 1; x <= n; ++x) {
			if (c[x][y] == 1) {
				found = 1;
				break;
			}

			if (s[x] && a[x]) {
				c[x][y] = 1;
				found = 1;
				break;				        
			}
		}

		if (found)
			continue;

		for (int x = 1; x <= n; ++x) {
			if (c[x][y] == -1 && !used[x]) {
				c[x][y] = 1;
				used[x] = 1;
				found = 1;
				break;
			}				
		}

		if (found)
			continue;

		for (int x = 1; x <= n; ++x) {
			if (c[x][y] == -1) {
				c[x][y] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
			Exit();
	}	


	for (int x = 1; x <= n; ++x) {
		int O = 0, A = 1;
		for (int y = 1; y <= n; ++y) {
			if (c[x][y] == -1)
				c[x][y] = 0; 
			O |= c[x][y];
			A &= c[x][y];
		}

		if ((!s[x] && A != a[x]) || (s[x] && O != a[x])) 
			Exit();		
	}
	
	for (int y = 1; y <= n; ++y) {
		int O = 0, A = 1;
		for (int x = 1; x <= n; ++x) {
			if (c[x][y] == -1)
				c[x][y] = 0; 
			O |= c[x][y];
			A &= c[x][y];
		}

		if ((!t[y] && A != b[y]) || (t[y] && O != b[y])) 
			Exit();		
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (c[i][j])
				res[i][j] += p;
	
	p += p;
	for (int i = 1; i <= n; ++i) {
		v[i] /= 2; 
		u[i] /= 2;
	}
}

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	for (int i = 1; i <= n; ++i)
		cin >> t[i];
	for (int i = 1; i <= n; ++i)
		cin >> u[i];
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	for (int i = 0; i < 64; ++i)
		solve();
	for (int i = 1; i <= n; ++i, cout << endl)
		for (int j = 1; j <= n; ++j)
			cout << res[i][j] << ' ';
}
