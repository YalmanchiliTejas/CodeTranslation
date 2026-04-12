#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

using ll = long long;

constexpr int MAX_N = 100000, mod = 1000000007;
constexpr ll INF = 1e17;

using P = std::pair<ll, int>;

struct edge
{ ll to, dist; };

int N, M;
int S, T;
std::vector<edge> G[MAX_N];
ll d1[MAX_N], d2[MAX_N];
ll dp1[MAX_N], dp2[MAX_N];
ll ans;

void dijkstra( int s, ll *ds, ll *dp )
{
  std::priority_queue<P, std::vector<P>, std::greater<P>> pque;
  pque.push( P( 0, s ) );
  std::fill( (ll*)ds, (ll*)(ds+N), INF );
  ds[s] = 0;
  dp[s] = 1;

  while( !pque.empty() )
  {
    P p = pque.top(); pque.pop();
    ll dist = p.first, v = p.second;

    if( ds[v] < dist )
      continue;

    for( auto &e : G[v] )
    {
      if( ds[e.to] > ds[v]+e.dist )
      {
        dp[e.to] = dp[v];
        ds[e.to] = ds[v]+e.dist;
        pque.push( P( ds[e.to], e.to ) );
      }
      else if( ds[e.to] == ds[v]+e.dist )
        dp[e.to] = (dp[e.to] + dp[v]) % mod;
    }
  }

  return;
}

int sqr( ll x )
{ return x%mod*x%mod; }

int main()
{
  scanf( "%d%d%d%d", &N, &M, &S, &T );
  --S; --T;
  rep( i, M )
  {
    ll U, V, D;
    scanf( "%lld%lld%lld", &U, &V, &D );
    --U; --V;
    G[U].push_back( (edge){ V, D } );
    G[V].push_back( (edge){ U, D } );
  }

  dijkstra( S, d1, dp1 );
  dijkstra( T, d2, dp2 );

  ans = dp1[T]*dp1[T] % mod;

  rep( i, N ) if( d1[i] == d2[i] && d1[i]+d2[i] == d1[T] )
    ans = (ans - sqr( dp1[i]%mod*dp2[i]%mod ) + mod) % mod;

  rep( i, N ) for( auto &e : G[i] )
  {
    int U = i, V = e.to, D = e.dist;

    //if( 2*d1[U[i]] > d1[T] )
      //std::swap( U[i], V[i] );

    //if( 2*d1[U[i]] < d1[T] && 2*d1[V[i]] > d1[T] && d1[U[i]]+D[i] == d1[V[i]] )
    if( 2*std::max( d1[U], d2[V] ) < d1[T] && d1[U]+D+d2[V] == d1[T] )
      ans = (ans - sqr( dp1[U]%mod*dp2[V]%mod ) + mod) % mod;
  }

  printf( "%lld\n", ans );

  return 0;
}