#include <cstdio>
#include <algorithm>
#include <map>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;
using P = std::pair<ll, ll>;

ll N, X;
ll two[60];
std::map<P, ll> dp;

ll calc( ll lev, ll x )
{
  ll ret = 0;

  if( dp.count( P( lev, x ) ) )
    return dp[P( lev, x )];

  if( !lev )
    return x > 0 ? 1 : 0;

  ret += calc( lev-1, std::min( two[lev+1]-3, x-1 ) );

  if( x-1 > two[lev+1]-2 )
    ret += calc( lev-1, x-1-two[lev+1]+2 );

  if( x-1 >= two[lev+1]-2 )
    ++ret;

  return dp[P( lev, x )] = ret;
}

int main()
{
  scanf( "%lld%lld", &N, &X );

  two[0] = 1;
  rep( i, N+2 )
    two[i+1] = two[i]*2;

  printf( "%lld\n", calc( N, X ) );

  return 0;
}