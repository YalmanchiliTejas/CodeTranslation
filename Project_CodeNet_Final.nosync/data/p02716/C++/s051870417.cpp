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
 
 
const int inf = 1e9, maxn = 4e5 + 148, mod = 1e9 + 7, N = 2e5 + 11;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 555;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;

int n, a[N], sum[N][2], ans, t[N << 2], add[N << 2];

int get (int l, int r, int i) {
	return sum[r][i] - sum[l - 1][i];
}

void push (int v) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];
		t[v << 1] += add[v];
		t[v << 1 | 1] += add[v];
		add[v] = 0;
	}
}


void update (int l, int r, int x, int v = 1, int tl = 0, int tr = n + 1) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		add[v] += x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);	
}

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
		for (int j = 0; j < 2; ++j) {
			sum[i][j] = sum[i - 1][j]; 
			if (i % 2 == j)
				sum[i][j] += a[i];
		}
	}

	if (n % 2 == 1) {
	    ans = sum[n - 1][1];
	    int j = n; 
		for (int i = n; i > 2; i -= 2) {
			update(0, j - 1, a[i]);
			update(j, n + 1, a[i - 1]);
			ans = max(ans, sum[i - 3][1] + t[1]);
			--j;
		}
	} else {
		ans = -INF;
		for (int i = 0; i <= n; i += 2)
			ans = max(ans, sum[i][1] + get(i + 1, n, 0));
	}	

	cout << ans << endl;	
}

