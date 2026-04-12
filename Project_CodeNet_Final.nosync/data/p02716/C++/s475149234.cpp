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

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, k;
ll a[N];
 
ll ans;
set < pair < ll, int > > s;
set < int > id;
 
 
int main () {
   	SpeedForce;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		s.insert({a[i], i});
		id.insert(i);
    }	
 
    id.insert(0);
    id.insert(n+1);
 
    for (int i = 1; i <= n / 2; i ++) {
    	auto it = *s.rbegin();
    	s.erase(it);
    	//cout << it.F << ' ' << it.S << '\n';
    	ans += it.F;
    	id.erase(it.S);
 
    	auto l = *(--id.lower_bound(it.S));
    	auto r = *id.lower_bound(it.S);
 
    	if (l > 0) {
    		a[it.S] -= a[l];
    		id.erase(l);
    		s.erase({a[l], l});
 
    	}
    	if (r <= n) {
    		a[it.S] -= a[r];
    		id.erase(r);
    		s.erase({a[r], r});
 
    	}
    	a[it.S] *= -1ll;
 
    	if (l >= 1 && r <= n) {
    		s.insert({a[it.S], it.S});
    		id.insert(it.S);
    	}
 
    //	cout << ans << '\n';
    }
    cout << ans << '\n';
    return Accepted;
}

// B...a