/*
* @Author: _dp95
* @Date:   2020-04-06 08:48:18
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

const int MAX = 2*1000*10 + 10 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

int n, k, dp[MAX][101][2] ;

int sol( string &s, int ind, int mod, bool flag ){
  if( ind == n )
    return !mod ;
  int &ans = dp[ind][mod][flag] ;
  if( ans != -1 )
    return ans ;
  ans = 0 ;
  int d = flag?9:(s[ind]-'0');
  for( int i = d ; i >= 0 ; i-- ){
    ans += sol( s, ind+1, (mod+i)%k, flag|(i<d) ) ;
    if( ans >= MOD )
      ans -= MOD ;
  }
  return ans ;
}

signed main( ){
  timesaver ;
  string s ;
  cin >> s >> k ;
  n = sz(s) ;
  mem( dp, -1 ) ;
  string a(n, '0');
  int r = sol( s, 0, 0, 0 ) ;
  mem( dp, -1 ) ;
  int l = sol( a, 0, 0, 0 ) ;
  cout << ( r - l + MOD )%MOD << nl ;
}