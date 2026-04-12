#include <cstdio>
#include <algorithm>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;
constexpr ll mod = 1000000007;

ll N, M, K;
ll ans;
ll fact[200010], inv[200010];

ll powMod( ll x, ll y, ll m )
{
  ll ret = 1;

  while( y > 0 )
  {
    if( y&1 )
      ret = (ret*x) % mod;

    x = x*x%m;

    y >>= 1;
  }

  return ret;
}

ll comb( ll n, ll r )
{ return fact[n]*inv[r]%mod*inv[n-r]%mod; }

int main()
{
  scanf( "%lld%lld%lld", &N, &M, &K );

  fact[0] = 1;
  rep( i, N*M )
    fact[i+1] = fact[i]*(i+1)%mod;
  rep( i, N*M+1 )
    inv[i] = powMod( fact[i], mod-2, mod );

  for( int d = 1; d <= N; ++d )
    ans = (ans+d*comb(N*M-2, K-2)%mod*(N-d)%mod*M%mod*M%mod) % mod;
  for( int d = 1; d <= M; ++d )
    ans = (ans+d*comb(N*M-2, K-2)%mod*(M-d)%mod*N%mod*N%mod) % mod;

  printf( "%lld\n", ans );

  return 0;
}