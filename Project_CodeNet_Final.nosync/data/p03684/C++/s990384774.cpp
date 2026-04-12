// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define PB push_back
#define N 101010
struct DisjointSet{
  // save() is like recursive
  // undo() is like return
  int n, fa[ N ], sz[ N ];
  vector< pair<int*,int> > h;
  vector<int> sp;
  void init( int tn ){
    n=tn;
    for( int i = 0 ; i < n ; i ++ ){
      fa[ i ]=i;
      sz[ i ]=1;
    }
    sp.clear(); h.clear();
  }
  void assign( int *k, int v ){
    h.PB( {k, *k} );
    *k = v;
  }
  void save(){ sp.PB(SZ(h)); }
  void undo(){
    assert(!sp.empty());
    int last=sp.back(); sp.pop_back();
    while( SZ(h)!=last ){
      auto x=h.back(); h.pop_back();
      *x.first = x.second;
    }
  }
  int f( int x ){
    while( fa[ x ] != x ) x = fa[ x ];
    return x;
  }
  void uni( int x , int y ){
    x = f( x ); y = f( y );
    if( x == y ) return;
    if( sz[ x ] < sz[ y ] ) swap( x, y );
    assign( &sz[ x ] , sz[ x ] + sz[ y ] );
    assign( &fa[ y ] , x);
  }
} djs;
void build(){

}
LL n , x[ N ] , y[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
  }
}
vector< pair<LL,pair<LL,LL>> > e;
vector< pair<pair<LL,LL>,LL> > v;
bool cmp1( pair<PLL,LL> p1 , pair<PLL,LL> p2 ){
  return p1.first.first < p2.first.first;
}
bool cmp2( pair<PLL,LL> p1 , pair<PLL,LL> p2 ){
  return p1.first.second < p2.first.second;
}
LL dist( int idx1 , int idx2 ){
  return min( abs( x[ idx1 ] - x[ idx2 ] ) ,
              abs( y[ idx1 ] - y[ idx2 ] ) );
}
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    v.push_back( { { x[ i ] , y[ i ] } , i } );
  sort( v.begin() , v.end() , cmp1 );
  for( int i = 1 ; i < n ; i ++ )
    e.push_back( { dist( v[ i - 1 ].second , v[ i ].second ) ,
                    { v[ i - 1 ].second , v[ i ].second } } );
  sort( v.begin() , v.end() , cmp2 );
  for( int i = 1 ; i < n ; i ++ )
    e.push_back( { dist( v[ i - 1 ].second , v[ i ].second ) ,
                    { v[ i - 1 ].second , v[ i ].second } } );
  sort( e.begin() , e.end() );
  djs.init( n );
  LL ans = 0;
  for( auto ee : e ){
    if( djs.f( ee.second.first ) ==
        djs.f( ee.second.second ) )
      continue;
    ans += ee.first;
    djs.uni( ee.second.first ,
             ee.second.second );
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
