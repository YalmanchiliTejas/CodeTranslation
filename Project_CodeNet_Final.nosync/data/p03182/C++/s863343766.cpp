#include <bits/stdc++.h>     
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define int ll
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;


int n, m, dp[maxn], s, ans = inf * inf;
vpii g[maxn], gr[maxn];
int t[4 * maxn], lz[4 * maxn];
void push(int v, int tl, int tr){
	if(!lz[v]) return;
	t[v] += lz[v];
	if(tl != tr)
		lz[v + v] += lz[v], lz[v + v + 1] += lz[v];
	lz[v] = 0;
}
void upd(int l, int r, int x, int v = 1, int tl = 0, int tr = n){
	push(v, tl, tr);
	if(l > r || tr < l || tl > r)
		return;
	if(l <= tl && tr <= r){
		lz[v] += x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(l, r, x, v + v, tl, tm);
	upd(l, r, x, v + v + 1, tm + 1, tr);
	t[v] = min(t[v + v], t[v + v + 1]);
}                        
int get(int l, int r, int v = 1, int tl = 0, int tr = n){
	push(v, tl, tr);
	if(l > r || tr < l || tl > r)
		return inf * inf;
	if(l <= tl && tr <= r){
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	return min(get(l, r, v + v, tl, tm), get(l, r, v + v + 1, tm + 1, tr));
}
main () {
	cin >> n >> m;
	forn(i, 1, m){
		int l, r, a;
		cin >> l >> r >> a;
		s += a;
		g[r].pb(mp(l, a));
	}
	forn(i, 1, n + 1){
		for(auto x : g[i - 1]){
			upd(0, x.f - 1, x.s);
		}
		dp[i] = get(0, i - 1);
		upd(i, i, dp[i]);
		ans = min(ans, dp[i]);
	}
	cout << s - ans;
}