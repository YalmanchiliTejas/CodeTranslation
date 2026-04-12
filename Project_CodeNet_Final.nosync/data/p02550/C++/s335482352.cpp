//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC target("avx,avx2")
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")

//# include <x86intrin.h>
# include <bits/stdc++.h>

# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9; 
const int N = 6e5+5;                                         
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd (int l, int r) {
	return uniform_int_distribution<int> (l, r)(gen);
}
ll ans, sum;
	
int main () {
	SpeedForce;
	ll n, x, m;
	cin >> n >> x >> m;
	x %= m;
	int len = 0;
	vector < int > u(m, -1);
	vector < ll > f(m);
	while(len < n && u[x] == -1) {
		u[x] = len;
		if(len) f[len] = f[len-1];
		f[len] += x;
		ans += x;
		x = x*(ll)x%m;
		++len;
	} 
	n -= len;
	ll sum = f[len-1];
	if(u[x]) sum -= f[u[x]-1];
	
	len -= u[x];
	
	ans += (n/len) * (ll)sum;
	n %= len;
	
	while(n > 0) {
		ans += x;
		x = x*(ll)x%m;
		--n;
	} 
	cout << ans << '\n';
	
	return Accepted;
}

// B...a
