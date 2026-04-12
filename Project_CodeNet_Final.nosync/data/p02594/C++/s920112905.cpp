#include<bits/stdc++.h>
using namespace std ;
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) (x.find( y ) != x.end())
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)1e9 + 7 ;
const int inf = (int)1e18 ;
void mxz( int &a, int b ){
	a = max( a, b ) ;
}

signed main(){
	int T ; cin >> T ;
	if( T >= 30 ) cout << "Yes" ;
	else cout << "No" ;
	return 0 ;
}
