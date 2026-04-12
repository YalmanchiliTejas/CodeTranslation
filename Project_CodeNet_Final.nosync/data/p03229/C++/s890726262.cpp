#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;

ll N;
ll A[100010];
std::vector<ll> cs[2];

// /\/\ (b-a)+(b-c)+(d-c)+(d-e) = -a+2b-2c+2d-e
// \/\/ (a-b)+(c-b)+(c-d)+(e-d) = a-2b+2c-2d+e

int main()
{
  scanf( "%lld", &N );
  rep( i, N )
    scanf( "%lld", A+i );

  std::sort( A, A+N );

  rep( i, N )
  {
    ll ret = 1;

    if( i >= 1 && i < N-1 )
      ret *= 2;

    cs[0].push_back( (i&1?1:-1)*ret );
  }

  rep( i, N )
  {
    ll ret = 1;

    if( i >= 1 && i < N-1 )
      ret *= 2;

    cs[1].push_back( (i&1?-1:1)*ret );
  }

  rep( i, 2 )
    std::sort( all( cs[i] ) );

  ll ans = 0;
  rep( i, 2 )
  {
    ll ret = 0;

    rep( k, N )
      ret += A[k]*cs[i][k];

    ans = std::max( ans, ret );
  }

  printf( "%lld\n", ans );

  return 0;
}