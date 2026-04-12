#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e6 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

ll n , m , s , t ;
vector<pll> G[N] ;
map<pll , ll> we ;
ll ds[N] , dt[N]  , dps[N] , dpt[N];
inline ll sum(ll a , ll b) {
	return (a + b ) % Mod ;
}
inline ll mul(ll a,  ll b) {
	return (a * b) % Mod ;
}
inline ll C2(ll x) {
	return mul(x , x ) ;
}
inline ll sub(ll a, ll b) {
	return (a - b + Mod) % Mod ;
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> n >> m >> s >> t;
    vector<pll> E ;
    for (int i = 0 ; i <m ; i  ++) {
    	ll v , u , w ;
    	cin >> v >> u >> w ;
    	G[v].pb({u , w}) ;
    	G[u].pb({v , w}) ;
    	E.pb({v , u}) ;
    	we[{v , u}] = we[{u , v}] = w ;
	}
	memset(ds , 63 , sizeof(ds)) ;
	memset(dt , 63 , sizeof(dt)) ;
	ds[s] = 0 ;
	dt[t] = 0 ;
	dps[s] = 1 ;
	dpt[t] = 1 ;
	set<pll> S ;
	for (int i = 1 ; i <= n ; i ++) S.insert({ds[i] , i}) ;
	while (S.size()) {
		auto x = *S.begin() ;
		S.erase(x) ;
		ll d = x.F ,v = x.S ;
		for (auto u : G[v]) {
			if (ds[u.F] > d + u.S) {
				S.erase({ds[u.F] , u.F}) ;
				ds[u.F] = d + u.S;
				dps[u.F] = dps[v] ;
				S.insert({ds[u.F] , u.F}) ;
				continue ;
			}
			if (ds[u.F] == d + u.S) {
				dps[u.F] += dps[v] ;
				dps[u.F] %= Mod ;
			} 
		}
	}
	for (int i = 1 ; i <= n ; i ++) S.insert({dt[i] , i}) ;
	while (S.size()) {
		auto x = *S.begin() ;
		S.erase(x) ;
		ll d = x.F , v = x.S ;
		for (auto u : G[v]) {
			if (dt[u.F] > d + u.S) {
				S.erase({dt[u.F] , u.F}) ;
				dt[u.F] = d + u.S ;
				dpt[u.F] = dpt[v] ;
				S.insert({dt[u.F] , u.F}) ;
				continue ;
			}
			if (dt[u.F] == d + u.S) {
				dpt[u.F] += dpt[v] ;
				dpt[u.F] %= Mod ;
			} 
		}
	}
	ll ans = C2(dpt[s]) ;
	//cout << ans << endl;
	ll SP = dt[s] ;
	for (int i= 1 ; i <= n ; i ++) {
		if (ds[i]  + dt[i] == SP && ds[i] * 2 == SP && dt[i] * 2 == SP) ans = sub(ans , C2(mul(dpt[i] , dps[i]))) ;
	}
	for (auto x : E) {
		if (ds[x.F] * 2  < SP && dt[x.S] * 2 < SP && ds[x.F] + we[{x.F , x.S}] + dt[x.S] == SP) {
			ans = sub(ans , C2(mul(dps[x.F] , dpt[x.S]))) ;
			//continue ;
		}
		if (ds[x.S] * 2  < SP && dt[x.F] * 2 < SP && ds[x.S] + we[{x.F , x.S}] + dt[x.F] == SP) {
			ans = sub(ans , C2(mul(dpt[x.F] , dps[x.S]))) ; 
		}
	}
	cout << ans << endl;
    return (0) ;
}