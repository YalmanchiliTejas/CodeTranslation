// In the name of God 
#include <bits/stdc++.h>

using namespace std ;
 
#define int long long
#define all(v) v.begin() , v.end()

template<typename T> inline bool smin(T &a, const T &b){ return b < a ? a = b,1:0;}
template<typename T> inline bool smax(T &a, const T &b){ return a < b ? a = b,1:0;}

const int N = 26 ; 

int n , res [ N ] , cnt [ N ] ; 

int32_t main()                     
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n ;
	memset ( res , 63 , sizeof res ) ; 
	while ( n -- ) {
		string s;
		cin >> s ;
		memset ( cnt , 0 , sizeof cnt ) ;
		for ( auto x : s )
			cnt [ x - 'a' ] ++ ;
		for ( int c = 0 ; c < N ; ++c )
			smin ( res [ c ] , cnt [ c ] ) ; 
	}
	for ( int c = 0 ; c < N ; ++c )
		while ( res [ c ] -- )
			cout << ( char ) ( c + 'a' ) ; 
}
