#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e3 + 17;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
 
int n, a[N*3], m, add, dp[N][N], b[N*3], mx[N], mx1;
bool good[N][N], good1[N];
 
main () {
	cin >> n;
	for (int i = 1; i <= n * 3; ++i)
		cin >> a[i];
 
	b[++m] = a[1];
	b[++m] = a[2];
 
	for (int j = 1; j < n; ++j) {
		if (a[j*3] == a[j*3 + 1] && a[j*3 + 1] == a[j*3 + 2]) {
			++add;
		} else {
			b[++m] = a[j*3];
			b[++m] = a[j*3 + 1];
			b[++m] = a[j*3 + 2];	
		}
	}
 
	b[++m] = a[n*3];
 
	good[b[1]][b[2]] = 1;
	good[b[2]][b[1]] = 1;
	good1[b[1]] = good1[b[2]] = 1;
 
	for (int i = 1; i < m / 3; ++i) {
		vi v;
		for (int j = 0; j < 3; ++j) 
			v.pb(b[i*3 + j]);
 
		vector < pair < pii, int > > V;
 
		for (int j = 1; j < 7; ++j) {
			vi v1, v2;
			for (int x = 0; x < 3; ++x)
				if (j & (1 << x))
					v1.pb(v[x]);
				else
					v2.pb(v[x]);
 
			if (sz(v1) == 1) {
				int a = v1[0], b = v2[0], c = v2[1];
				V.pb({{b, c}, mx1});
				if (good[a][a])
					V.pb({{b, c}, dp[a][a] + 1});
			} else {
				int a = v2[0], b = v1[0], c = v1[1];
				if (b == c) {
					for (int x = 1; x <= n; ++x) 
						if (good[x][b]) 
							V.pb({{x, a}, dp[x][b] + 1});					
				}
 
				for (int x = 1; x <= n; ++x) 
					if (good1[x])
						V.pb({{x, a}, mx[x]});
			}
		}
 
		for (auto x : V) {
			good1[x.f.f] = good1[x.f.s] = 1;
			good[x.f.f][x.f.s] = good[x.f.s][x.f.f] = 1;
			dp[x.f.f][x.f.s] = max(dp[x.f.f][x.f.s], x.s);
			dp[x.f.s][x.f.f] = max(dp[x.f.s][x.f.f], x.s);
			mx1 = max(mx1, x.s);
			mx[x.f.f] = max(mx[x.f.f], x.s);
			mx[x.f.s] = max(mx[x.f.s], x.s);
		}
 
	}
 
	int ans = 0;
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			if (good[x][y]) 
				ans = max(ans, dp[x][y] + (x == y && y == b[m])); 
			
 
 
	cout << ans + add << endl;
}