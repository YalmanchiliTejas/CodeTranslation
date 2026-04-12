#include <iostream>
#include <fstream>

using namespace std;

#define f(i, n) for( int i = 1; i <= n; i++ )


const int N = 10005;
long long v[N], dp[N][N];
int n;


int main()
{
  long long sum = 0;
  int i = 1, val = 3;


  cin >> n;
  f(i, n){
      cin >> v[i];
      sum += v[i];
  }

  f(i, n)
    f(j, n)
      if(i == j)
        dp[i][j] = v[i];
      else if(j == i + 1 )
        dp[i][j] = max(v[i], v[j]);

  while(i <= n - 2)  {
      int j = val;
      int x = 1;
      while(j <= n){
          dp[x][j] = max( v[x] + min( dp[x + 2][j], dp[x + 1][j - 1]), v[j] + min( dp[x + 1][j - 1], dp[x][j - 2]));
          j++;
          x++;
      }
      val ++;
      i ++;
  }


  cout << dp[1][n] - (sum - dp[1][n]);
  return 0;
}
