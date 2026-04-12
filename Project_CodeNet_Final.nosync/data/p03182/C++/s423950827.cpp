// In the Name of Allah
// Ya Ali!
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin() , x.end()

const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll INF = 1e18 ;

ll n , m , dp[ maxn ] , maxx[ 4*maxn ] , la[ 4*maxn ] , ans = 0 ;
vector < pair < ll , ll > > vl[ maxn ] , vr[ maxn ] ;

ll poww( ll a , ll b)
{
  if( b == 0 )return 1 ;
  ll x = poww( a , b/2 )%mod ;
  if( b & 1) return (((x*x)%mod)*a)%mod ;
  else return (x*x)%mod ;
}

void shift( int l , int r , int node)
{
  maxx[ node ] += la[ node ];

  if(l == r){
    la[ node ] = 0;
    return ;
  }

  la[ node+node ] += la[ node ];
  la[ node+node+1 ] += la[ node ];
  la[ node ] = 0;
}

void add( int x , int y , ll va , int l = 0 , int r = n , int node = 1)
{
 shift( l , r , node) ;

 if(l > y || r < x )return ;
 if(l >= x && r <= y){
   la[ node ] += va;
   shift( l , r , node) ;
   return ;
 }

 int mid = (r+l)/2 ;
 add( x , y , va , l , mid , node + node) ;
 add( x , y , va , mid+1 , r , node+node+1);

 maxx[ node ] = max( maxx[ node+node] , maxx[ node+node+1 ]) ;
}

ll getmax( int x , int y , int l = 0 , int r = n , int node = 1)
{
  if( l > y || r < x)
    return -INF;
  if(l >= x && r <= y)
    return maxx[ node ];

  int mid = (r+l)/2 ;
  return max( getmax(x , y , l , mid , node+node) , getmax( x , y , mid+1 , r , node+node+1 ));
}

signed main()
{
 ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

 cin >> n >> m ;
 for(int i = 1 ; i <= m ; i ++){
   ll l , r , a ;
   cin >> l >> r >> a ;
   vr[ r ].pb({ l , a }) ;
   vl[ l ].pb({ l , a }) ;
 }

 for(int i = 1 ; i <= n ; i ++){
   // on
   for(auto pp : vl[ i ])
      add( 0 , pp.F-1 , pp.S) ;

   dp[ i ] = getmax(0 , i-1);

   add( i , i , dp[ i ]) ;

   //off
   for(auto pp : vr[ i ])
      add( 0 , pp.F-1 , -pp.S);

   ans = max( ans , dp[ i ]) ;
 }

 cout << ans ;

    return 0;
}
