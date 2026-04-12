//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 2e5 + 20 , mod = 1e9 + 7 ;
const ll inf = 1e18 + 20 ;

int n , m , S , T ;

ll dist[2][N] ;
int num[2][N] ;
vector <pii> g[N] ;
vector <pair <pii , int>> edges ;

int ans ;

inline void add (int &a , int b) {
	a += b ;
	if (a >= mod) a -= mod ;
}

inline void dijk (int S , ll dist[N] , int num[N]) {
	for (int i = 0 ; i < n ; i ++)
		dist[i] = inf , num[i] = 0 ;

	dist[S] = 0 ;
	num[S] = 1 ;

	set <pair <ll , int>> st ;

	st.insert({0 , S}) ;

	while (_sz(st)) {
		int v = st.begin() -> S ;

		st.erase(st.begin()) ;

		for (pii ed : g[v]) {
			int u = ed.F , w = ed.S ;

			if (dist[v] + w < dist[u]) {
				st.erase({dist[u] , u}) ;
				num[u] = 0 ;
				dist[u] = dist[v] + w ;
				st.insert({dist[u] , u}) ;
			}		
		
			if (dist[v] + w == dist[u]) add(num[u] , num[v]) ;
		}
	}
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> m ;
	cin >> S >> T ;
	S -- , T -- ;

	for (int i = 0 , u , v , w ; i < m ; i ++) {
		cin >> u >> v >> w ;
		u -- , v -- ;
	
		g[u].push_back({v , w}) ;
		g[v].push_back({u , w}) ;

		edges.push_back({{u , v} , w}) ;
	}

	dijk(S , dist[0] , num[0]) ;
	dijk(T , dist[1] , num[1]) ;

	ans = 1ll * num[0][T] * num[1][S] % mod ;

	for (int i = 0 ; i < n ; i ++) {
		if (dist[0][i] == dist[1][i] && dist[0][i] + dist[1][i] == dist[0][T]) {
			add(ans , mod - 1ll * num[0][i] * num[1][i] % mod * num[0][i] % mod * num[1][i] % mod) ; 	
		}
	}

	for (int i = 0 ; i < m ; i ++) {
		int u = edges[i].F.F , v = edges[i].F.S , w = edges[i].S ;

		if (dist[0][u] > dist[0][v]) swap(u , v) ;

		if (dist[0][u] + w + dist[1][v] == dist[0][T] && 2 * dist[0][u] < dist[0][T] && 2 * dist[1][v] < dist[0][T]) {
			add(ans , mod - 1ll * num[0][u] * num[1][v] % mod * num[0][u] % mod * num[1][v] % mod) ;
		}
	}

	cout << ans << '\n' ;
}
