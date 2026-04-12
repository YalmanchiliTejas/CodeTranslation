#include<bits/stdc++.h>
using namespace std ;

/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
int mod = (int)1e9 + 7 ;

/************************************************************/

auto accumulate( vector<int> &a, int &n ){
	vector<int> prefix( n, 0 ) ;
	prefix[0] = a[0] % mod ;
	for( int i = 1 ; i < n ; i++ ){
		(prefix[i] = prefix[i-1] + a[i]) %= mod ;
	}
	return prefix ;
} 
int sum( vector<int> &a, int f, int t ){
	return (( a[t] - (( f == 0 ) ? 0 : a[f-1]) ) + mod) % mod ;
}


signed main(){
	int n ; cin >> n ;
	vector<int> a(n) ;
	for( int i = 0 ; i < n ; i++ ) cin >> a[i] ;
	int ans = 0 ;
	let prefix = accumulate( a, n ) ;
	// for( let p of prefix ) cout << p << " " ; cout << endl;
	for( int i = 0 ; i < n - 1 ; i++ ){
		// cout << sum( prefix, i + 1, n - 1 ) << endl ;
		ans += ( a[i] * sum( prefix, i + 1, n - 1 ) ) ;
		ans %= mod ;
	}
	cout << ans ;	
	return 0 ;
}