#include <bits/stdc++.h>     
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)1e7 + 100;
const int mod = (int)998244353;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;

int f[maxn], inv[maxn], pw[maxn], ans;
int n, s;

int binpow(int a, int b){
	int res = 1;
	while(b){
		if(b & 1)
			res = (res * 1ll * a) % mod;
		b >>= 1;
		a = (a * 1ll * a) % mod;
	}
	return res;
}
int C(int n, int k) {
  if (k > n || k < 0) return 0;
  int res = f[n];
  res = res * 1ll * inv[k] % mod;
  res = res * 1ll * inv[n - k] % mod;
  return res;
}
main () {
	f[0] = pw[0] = 1;
  forn(i, 1, maxn - 1)
	f[i] = f[i - 1] * 1ll * i % mod, pw[i] = pw[i - 1] * 2ll % mod;
    inv[maxn - 1] = binpow(f[maxn - 1], mod - 2);
	forev(i, maxn - 1, 1)
  	inv[i - 1] = inv[i] * 1ll * i % mod;
	cin >> n;
	forn(a, n / 2 + 1, n){
		ans = (ans + C(n, a) * 1ll * pw[n - a] % mod) % mod;
	}	
	ans = (ans + ans) % mod;
	cout << (binpow(3, n) - ans + mod) % mod;
}