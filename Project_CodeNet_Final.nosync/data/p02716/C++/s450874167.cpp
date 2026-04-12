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
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N;
ll A[200010];
ll dp[200010][2][3];

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> A[i];

  rep( i, N+1 ) rep( j, 2 ) rep( k, 3 )
    dp[i][j][k] = -(1ll<<60);

  dp[0][1][0] = 0;

  rep( i, N )
  {
    rep( j, 2 ) rep( k, 3 )
    {
      if( j+k < 3 )
        chmax( dp[i+1][1][j+k], dp[i][j][k] );
      
      if( j == 1 )
        chmax( dp[i+1][0][k], dp[i][j][k]+A[i] );
    }
  }

  if( N%2 == 0 )
  {
    std::cout << std::max( dp[N][0][1], dp[N][1][0] ) << std::endl;
  }
  else
  {
    std::cout << std::max( dp[N][0][2], dp[N][1][1] ) << std::endl;
  }

  return 0;
}