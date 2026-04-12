#include <cstdio>
#include <algorithm>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;

ll N, K;
ll ans;

int main()
{
  scanf( "%lld%lld", &N, &K );

  repi( b, K+1, N+1 )
    ans += (N/b)*(b-K)+std::max<ll>(0, N-(N/b)*b+(K==0?0:1)-K);
  
  printf( "%lld\n", ans );

  return 0;
}