#include <bits/stdc++.h>
  
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
  
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
#define setp(x) fixed << setprecision(x)
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 1e6 + 555; // TL MB
const double PI = acos(-1.0);
void mul(ll &x, ll y){
	x *= y;
	if(x >= mod) x %= mod;
}
 
void add(ll &x, ll y){
	x += y;
	if(x >= mod) x -= mod;
	if(x < 0) x += mod;
}
ll bp(ll a, ll n){
	ll r = 1;
	while(n){
		if(n & 1) mul(r, a);
		mul(a, a);
		n >>= 1;
	}
 
}

int p[N];
int get(int v){
	return v == p[v] ? v : p[v] = get(p[v]);
}
void solve()
{
	int n;
	cin >> n;
	vector<pii> x(n), y(n);
	set<pair<int, pii> > px, py;
	rep(i, n) p[i] = i;
	rep(i, n){
		cin >> x[i].F >> y[i].F;
		x[i].S = y[i].S = i;
	}
	sort(all(x));
	sort(all(y));
	rep(i, n){
		if(i){
			px.insert({x[i].F - x[i - 1].F, {x[i].S, x[i - 1].S}});
			py.insert({y[i].F - y[i - 1].F, {y[i].S, y[i - 1].S}});
		}
	}
	ll res = 0;
	while(!px.empty() && !py.empty()){
		pair<int, pii> u = *px.begin();
		pair<int, pii> v = *py.begin();
		if(u.F <= v.F){
			res += 1ll * u.F;
			int x = get(u.S.F), y = get(u.S.S);
			p[y] = x;
			px.erase(px.begin());
		}
		else{
			res += 1ll * v.F;
			int x = get(v.S.F), y = get(v.S.S);
			p[y] = x;
			py.erase(py.begin());	
		}
		while(!px.empty()){
			pair<int, pii> x = *px.begin();
			if(get(x.S.F) == get(x.S.S)) px.erase(px.begin());
			else break;
		}
		while(!py.empty()){
			pair<int, pii> x = *py.begin();
			if(get(x.S.F) == get(x.S.S)) py.erase(py.begin());
			else break;
		}
	}
	cout << res;


}	 

 
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    Red;
  	int T = 1;
  	// cin >> T;
  	for(int i = 1; i <= T; ++i){
  		solve();
  	}
  	return 0;

}
