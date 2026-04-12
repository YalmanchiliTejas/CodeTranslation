/*  ***  In The Name of God ... ***  */
#include <bits/stdc++.h>

using namespace std ;
 
typedef long long ll ;
typedef long double ld ;

 
#define int long long
#define all(v) v.begin() , v.end()

template<typename T> inline bool smin(T &a, const T &b){ return b < a ? a = b,1:0;}
template<typename T> inline bool smax(T &a, const T &b){ return a < b ? a = b,1:0;}

const int N = ( int ) 1e5 + 10 ;

int n , sz [ N ] ; 
vector < int > adj [ N ] ;

bool dfs ( int v = 0 , int p = -1 ) { 
	bool ret = true ;
	sz [ v ] = 1 ;
	int odd = 0 ; 
	for ( int u : adj [ v ] ) {
		if ( u ^ p ) {
			ret &= dfs ( u , v ) ;
			sz [ v ] += sz [ u ] ;
			odd += ( sz [ u ] & 1 ) ; 
		}
	}
	odd += ( ( n - sz [ v ] ) & 1 ) ;
	ret &= ( odd <= 1 ) ;
	return ret ; 
}

int32_t main()                     
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n ;
	for ( int i = 0 ; i < n - 1 ; ++ i ) {
		int u , v ;
		cin >> u >> v ;
		-- u , -- v ; 
		adj [ u ] . push_back ( v ) ;
		adj [ v ] . push_back ( u ) ;
	}
	cout << ( dfs ( ) ? "Second" : "First" ) << '\n' ;  
}
