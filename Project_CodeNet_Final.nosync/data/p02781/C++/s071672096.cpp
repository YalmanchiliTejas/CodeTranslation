#include <iostream>
#include <string>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

std::string N;
ll K;
ll dp[110][2][5];

int main()
{
  std::cin >> N >> K;

  dp[0][0][0] = 1;

  rep( i, N.size() )
  {
    rep( j, 2 )
    {
      rep( k, K+1 )
      {
        rep( d, (j ? 9 : N[i]-'0')+1 )
        {
          dp[i+1][j || d < (N[i]-'0')][k+(d?1:0)] += dp[i][j][k];
        }
      }
    }
  }

  printf( "%lld\n", dp[N.size()][0][K]+dp[N.size()][1][K] );

  return 0;
}