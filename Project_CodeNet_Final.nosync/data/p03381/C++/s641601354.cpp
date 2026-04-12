#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
typedef long long LL;
using namespace __gnu_pbds;
typedef tree<LL,null_type,less<LL>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#include <ext/pb_ds/assoc_container.hpp>
#define N 202020
LL n , a[ N ];
int main(){
  scanf( "%lld" , &n );
  for( LL i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &a[ i ] );
  set_t s;
  for( LL i = 0 ; i < n ; i ++ )
    s.insert( a[ i ] * N + i );

  for( LL i = 0 ; i < n ; i ++ ){
    s.erase( a[ i ] * N + i );
    printf( "%lld\n" , *s.find_by_order( n / 2 - 1 ) / N );
    s.insert( a[ i ] * N + i );
  }
}
