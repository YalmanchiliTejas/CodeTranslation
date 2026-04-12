#include <cstdio>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;

constexpr ll MAX_N = 1000, mod = 1000000007;

ll N;
ll A, B, C, D;
ll dp[MAX_N+2][MAX_N+2];
ll fact[MAX_N+2], inv[MAX_N+2], invF[MAX_N+2];

ll powMod( ll x, ll y )
{
  ll ret = 1;

  while( y > 0 )
  {
    if( y & 1 )
      ret = (ret*x) % mod;

    x = (x*x) % mod;
    y >>= 1;
  }

  return ret;
}

int main()
{
  scanf( "%lld%lld%lld%lld%lld", &N, &A, &B, &C, &D );

  fact[0] = 1;
  rep( i, N )
    fact[i+1] = (ll)((i+1)*fact[i]) % mod;

  inv[0] = 1;
  invF[0] = 1;
  invF[N] = powMod( fact[N], mod-2 );
  rep( i, N )
    inv[i+1] = powMod( i+1, mod-2 );
  for( int i = N-1; i >= 0; --i )
    invF[i] = invF[i+1]*(i+1)%mod;

  rep( i, B+2 )
    dp[i][0] = 1;
  repi( k, A, B+1 ) repi( n, 0, N+1 )
  {
    if( !dp[k][n] )
      continue;

    if( n )
      dp[k+1][n] = ( dp[k+1][n] + dp[k][n] ) % mod;

    ll tmp = 1;

    repi( x, 1, D+1 )
    {
      if( N-n-k*x < 0 )
        break;

      tmp = (tmp * fact[N-n-k*(x-1)]%mod*invF[k]%mod*invF[N-n-k*x]%mod*inv[x]) % mod;
      
      if( C <= x && x <= D )
        dp[k+1][n+k*x] = ( dp[k+1][n+k*x] +  tmp*dp[k][n]%mod ) % mod;
    }
  }

  printf( "%lld\n", dp[B+1][N] );
  
  return 0;
}
