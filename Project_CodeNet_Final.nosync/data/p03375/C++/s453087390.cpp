#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

using ll = long long;

constexpr int MAX_N = 3000;

ll N, M;
ll dp[MAX_N+1][MAX_N+1];
ll pw[MAX_N*MAX_N+1], ppw[MAX_N+1];
ll comb[MAX_N+1][MAX_N+1];

ll powMod( ll x, ll y )
{
  ll ret = 1;

  while( y > 0 )
  {
    if( y & 1 )
      ret = (ret*x)%M;

    y >>= 1;
    x = (x*x)%M;
  }

  return ret;
}

int main()
{
  scanf( "%lld%lld", &N, &M );

  dp[0][0] = dp[1][0] = dp[1][1] = 1;
  repi( i, 2, N+1 )
  {
    dp[i][0] = 1;

    repi( j, 1, i+1 )
      dp[i][j] = (dp[i-1][j]+j*dp[i-1][j]+dp[i-1][j-1]) % M;
  }

  rep( i, N+1 )
    comb[i][0] = comb[i][i] = 1;

  repi( i, 1, N+1 ) repi( j, 1, N+1 )
    comb[i][j] = (comb[i-1][j-1]+comb[i-1][j]) % M;

  pw[0] = 1;
  rep( i, N*N )
    pw[i+1] = 2*pw[i]%M;

  ppw[0] = 2;
  rep( i, N )
    ppw[i+1] = ppw[i]*ppw[i]%M;

  ll ans = 0;
  rep( k, N+1 )
  {
    int sgn;
    if( k % 2 == 0 )
      sgn = 1;
    else
      sgn = -1;

    ll way = 0, tmp = pw[N-k], t = 1;
    rep( x, k+1 )
    {
      way = (way + dp[k][x]*t)%M;
      t = (t*tmp) % M;
    }

    ans = (ans + sgn*comb[N][k]%M*ppw[N-k]%M*way%M + M) % M;
  }

  printf( "%lld\n", ans%M );

  return 0;
}