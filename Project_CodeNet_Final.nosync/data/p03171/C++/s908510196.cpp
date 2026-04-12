/*
* @Author: _dp95
* @Date:   2020-01-30 10:21:41
*/
#include "bits/stdc++.h"
using namespace std ;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll ;
typedef long double ldb ;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define nl '\n'

#define all( x ) x.begin(),x.end() 
#define sz( x ) ( int )( x ).size( )
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );
#define bitcount( x ) __builtin_popcountll( x )

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int MAX = 3*1000 + 10 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

ll n, ar[MAX], sum, dp[MAX][MAX][2] ;

ll sol( ll l, ll r, ll flag ){
	if( l == r ){
		return flag?0:ar[l] ;
	}
	if( l > r )
		return 0 ;
	ll &ans = dp[l][r][flag] ;
	if( ans != -1 )
		return ans ;
	if( flag == 0 ){
		ans = ar[l] + sol( l+1, r, flag^1 ) ;
		ans = max( ans, ar[r] + sol( l, r-1, flag^1 ) ) ;
	}
	else{
		ans = sol( l+1, r, flag^1 ) ;
		ans = min( ans, sol( l, r-1, flag^1 ) ) ;
	}
	return ans ;
}

int main( ){
  timesaver ;
  cin >> n ;
  for( ll i = 0 ; i < n; i++ ){
  	cin >> ar[i] ;
  	sum += ar[i] ;
  }
  mem( dp, -1 ) ;
  cout << 2*sol( 0 , n-1, 0 )-sum << nl ;
}