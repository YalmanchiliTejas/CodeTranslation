#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

ll n , M[N] , H[N] , p[N] ;
set<ll> G[N] ;
set<pll> s ;
void DFS(ll v , ll par = -1 , ll h = 0) {
	H[v] = h ;
	M[v] = 1 ;
	p[v] = par; 
	for (auto u : G[v]) if (!M[u]) DFS(u , v , h + 1) ;
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> n ;
    for (int i = 0 ; i < n - 1;  i ++) {
    	ll v, u ;
    	cin >> v >> u ;
    	G[v].insert(u) ;
    	G[u].insert(v) ;
	}
    DFS(1) ;
    string ans = "Second" ;
    for (int i = 1 ; i <= n ; i ++) s.insert({H[i] , i}) ;
    while (s.size()) {
    	auto x = *s.rbegin() ;
    	ll d = x.F , v = x.S ;
    	if (p[v] == -1 || s.find({H[p[v]] , p[v]}) == s.end()) {
    		ans = "First" ;
    		break ;
		}
		s.erase(x) ;
		s.erase({d - 1 , p[v]}) ;
		for (auto u : G[v]) G[u].erase(v) ;
		for (auto u : G[p[v]]) G[p[v]].erase(p[v]) ;
		
	}
	if (s.size()) ans = "First" ;
	cout << ans ;
    return (0) ;
}