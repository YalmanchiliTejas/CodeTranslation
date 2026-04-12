#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N, K;

int main()
{
  std::cin >> N >> K;

  ll ans = 0;

  repi( i, 1, N+1 ) if( i-K >= 0 )
  {
    if( K )
      ans += N/i*(i-K)+(N%i ? std::max( 0ll, N%i-(K-1) ) : 0);
    else
      ans += N;

    //std::cout << N/i*(i-K)+(K ? std::max( 0ll, N%i-(K-1) ) : 0) << std::endl;
  }

  std::cout << ans << std::endl;

  return 0;
}