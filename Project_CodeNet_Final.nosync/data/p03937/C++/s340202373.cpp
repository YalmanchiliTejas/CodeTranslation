/*  ***  In The Name of God ... ***  */
#include <bits/stdc++.h>

using namespace std ;
 
#define int long long
#define all(v) v.begin() , v.end()

template<typename T> inline bool smin(T &a, const T &b){ return b < a ? a = b,1:0;}
template<typename T> inline bool smax(T &a, const T &b){ return a < b ? a = b,1:0;}

const int N = 10 ; 

int n , m ;
string s [ N ] ;
bool mark [ N ] [ N ] ; 

bool dfs ( int x , int y ) {
	if ( s [ x ] [ y ] != '#' )
		return false ;
	mark [ x ] [ y ] = true ; 
	if ( x == n - 1 && y == m - 1 )
		return true ;
	int ret = 0 ; 
	if ( x + 1 < n && s [ x + 1 ] [ y ] == '#' )
		++ ret ;
	if ( y + 1 < m && s [ x ] [ y + 1 ] == '#' )
		++ ret ;
	if ( ret != 1 )
		return false ;
	
	if ( x + 1 < n && s [ x + 1 ] [ y ] == '#' )
		return dfs ( x + 1 , y ) ; 
	if ( y + 1 < m && s [ x ] [ y + 1 ] == '#' )
		return dfs ( x , y + 1 ) ; 
}

int32_t main()                     
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; ++ i )
		cin >> s [ i ] ;
	bool okay = dfs ( 0 , 0 ) ;
	if ( !okay ) return cout << "Impossible" , 0 ; 
	for ( int i = 0 ; i < n ; ++ i )
		for ( int j = 0 ; j < m ; ++ j )
			if ( mark [ i ] [ j ] ^ ( s [ i ] [ j ] == '#' ) )
				return cout << "Impossible" , 0 ;
	cout << "Possible" ; 
}
