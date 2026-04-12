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
const int inf = 1e9, maxn = 4e5 + 148, mod = 998244353, N = 1e7 + 5;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;

int n, ans, p[N], f[N], rf[N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;
	}

	return res;
}

int rev (int x) {
	return binpow(x, mod - 2);
}

void precalc () {
	f[0] = 1;
	forn (i, 1, N - 1)
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[N - 1] = rev(f[N - 1]);
	forev (i, N - 2, 0)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;

	p[0] = 1;
	forn (i, 1, N - 1)
		p[i] = p[i - 1] * 2ll % mod;
}

int cnk (int n, int k) {
//	cerr << f[n] << ' ' << rf[k] << ' ' << rf[n - k] << endl;
	return f[n] * 1ll * rf[k] % mod * 1ll * rf[n - k] % mod;
}


void add (int &x, int y) {
	x += y;
	if (x < 0)
		x += mod;
	if (x >= mod)
		x -= mod;
}


main () {
	precalc();
	cin >> n;
	ans = 1;
	forn (i, 1, n)
		ans = ans * 3ll % mod;	

	forn (i, n / 2 + 1, n)	{	
		add(ans, -cnk(n, i) * 2ll * p[n - i] % mod); 
	}
	cout << ans << endl;
}
