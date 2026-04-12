#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;
using P = std::pair<ll, int>;

constexpr int MAX_N = 100000;
constexpr ll INF = 1e17, mod = 1000000007;

struct edge
{ int from, to; ll cost; };

int N, M;
int S, T;
std::vector<P> G[MAX_N+10];
ll d[2][MAX_N+10], dp[2][MAX_N+10];
ll ans;

void dijkstra( int s, int idx )
{
  std::fill( d[idx], d[idx]+N, INF );

  std::priority_queue<P, std::vector<P>, std::greater<P> > pque;

  pque.push( P( 0, s ) );
  d[idx][s] = 0;
  dp[idx][s] = 1;

  while( !pque.empty() )
  {
    P p = pque.top(); pque.pop();
    ll dist = p.first;
    int v = p.second;

    if( d[idx][v] < dist )
      continue;

    for( auto &e : G[v] )
    {
      ll cost = e.first;
      int u = e.second;

      if( d[idx][u] > d[idx][v]+cost )
      {
        dp[idx][u] = dp[idx][v];
        d[idx][u] = d[idx][v]+cost;
        pque.push( P( d[idx][u], u ) );
      }
      else if( d[idx][u] == d[idx][v]+cost )
        dp[idx][u] = (dp[idx][u]+dp[idx][v]) % mod;
    }
  }

  return;
}

ll sqr( ll x )
{ return x%mod*x%mod; }

int main()
{
  scanf( "%d%d%d%d", &N, &M, &S, &T );
  --S; --T;
  rep( i, M )
  {
    int U, V;
    ll D;
    scanf( "%d%d%lld", &U, &V, &D );

    --U; --V;
    G[U].push_back( P( D, V ) );
    G[V].push_back( P( D, U ) );
  }

  dijkstra( S, 0 );
  dijkstra( T, 1 );

  ans = (dp[0][T]*dp[0][T]) % mod;

  rep( i, N ) if( 2*d[0][i] == d[0][T] && d[0][i] == d[1][i] )
    ans = (ans-sqr(dp[0][i]*dp[1][i]%mod)+mod) % mod;

  rep( i, N ) for( auto &e : G[i] )
  {
    int u = i, v = e.second;
    ll D = e.first;
   
    if( 2*std::max( d[0][u], d[1][v] ) < d[0][T] && d[0][u]+D+d[1][v] == d[0][T] )
      ans = (ans-sqr(dp[0][u]*dp[1][v]%mod)+mod) % mod;
  }

  printf( "%lld\n", ans );

  return 0;
}