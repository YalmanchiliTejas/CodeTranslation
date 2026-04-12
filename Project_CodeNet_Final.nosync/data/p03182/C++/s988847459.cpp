// Marcin Knapik
#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
//#include <ext/pb_ds/assoc_container.hpp> // order_of_key
//#include <ext/pb_ds/tree_policy.hpp> // find by order
//using namespace __gnu_pbds; 
//#define ordered_set tree< int , null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>  
 
// const ll MAX_LL = 0xFFFFFFFFFFFFFFFF;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define losuj(a, b) uniform_int_distribution<ull>(a, b)(rng)
#define losuj_real(a, b) uniform_real_distribution<long double>(a, b)(rng)
 
typedef long double             ld;
typedef long long               ll;
typedef unsigned long long      ull;
typedef pair<ll, ll>            pll;
typedef pair<int, int>          ii;
typedef vector<int>             vi;
typedef vector<ii>              vii;
typedef vector<vi>              vvi;
typedef vector<vector<ii>>      vvii;
typedef vector< ll >            vll;
typedef vector< pll >           vpll;
 
#define sz(a)                   (int)(a).size()
#define pb                      push_back
#define all(c)                  (c).begin(), (c).end()
#define rall(c)                 (c).rbegin(), (c).rend()
#define FOR(i, a)               for (int i = 0; i < (a); i++)
#define f                       first
#define s                       second
#define rr "\e[31m "
#define bb "\e[m "
 
template <class T> inline bool setmin(T &a, T b){if (a > b)return a = b, 1;return 0;}
template <class T> inline bool setmax(T &a, T b){if (a < b)return a = b, 1;return 0;}
 
template<class T> inline  T fast(T a,T b,T mod) {ll res = 1; while(b){if(b&1) res = (res*a)%mod;a = (a*a)%mod;b >>= 1;}return res;}
template<class T> inline  T russian(T a, T b, T mod) {ll res = 0; while(b){if(b&1) res = (res + a)%mod; a = (a+a)%mod; b>>=1;}return res;}
template<class T> istream &operator>>(istream &os, vector<T> &container){for (auto &u : container)os >> u;return os;}
template<class T> ostream &operator<<(ostream &os, const vector<T> &container){for (auto &u : container)os << u << " ";return os;}
template<class T> inline  T gcd(T a, T b) { while (b)swap(a %= b, b); return a; }
 
const ll INF = 1e9 + 7;
const ll mod = 998244353;
const ll N = 1e6+7;
const ll T = 1<<20;
const ll BIG_INF = 1e18 + 7;
 
ll n, m, k;

ll tree[T * 2];
ll lazy[T * 2];
ll dp[N];

void push(int v){
	tree[v] += lazy[v];
	if(v < T){
		lazy[v * 2] += lazy[v];
		lazy[v * 2 + 1] += lazy[v];
	}
	lazy[v] = 0;
}

ll ask(int pocz, int kon, int u = 1, int lo = 0, int hi = T - 1){
	push(u);
	if(kon < lo or hi < pocz)
		return -BIG_INF;
	if(pocz <= lo and hi <= kon)
		return tree[u];
	int mid = (lo + hi) / 2;
	return max(ask(pocz, kon, u * 2, lo, mid), ask(pocz, kon, u * 2 + 1, mid + 1, hi));
}

void add(int pocz, int kon, ll val, int u = 1, int lo = 0, int hi = T - 1){
	push(u);
	if(kon < lo or hi < pocz)
		return;
	if(pocz <= lo and hi <= kon){
		lazy[u] += val;
		push(u);
		return;
	}
	int mid = (lo + hi) / 2;
	add(pocz, kon, val, u * 2, lo, mid);
	add(pocz, kon, val, u * 2 + 1, mid + 1, hi);
	tree[u] = max(tree[u * 2], tree[u * 2 + 1]);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vvi events;

	FOR(i, m){
		int a, b, c;
		cin >> a >> b >> c;

		events.pb({a, 1, c});
		events.pb({b + 1, -1, a, c});
	}

	sort(all(events));
	ll maxi = 0;
	dp[0] = 0;
	int id = 0;
	for(int i = 1; i <= n; i++){
		while(id < sz(events) and events[id][0] == i){
			if(events[id][1] == 1)
				add(0, i-1, events[id][2]);
			else
				add(0, events[id][2] - 1, -events[id][3]);
			id++;
		}
		dp[i] = ask(0, i-1);
		add(i, i, dp[i]);
		maxi = max(maxi, dp[i]);
	}	
	cout << maxi << '\n';
}	