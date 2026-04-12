#include <bits/stdc++.h>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)  
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define forl(i, n, st) for (ll i = (ll)st; i < (ll)(n); i++) 

ll calc(string value, int keta)
{
  int MAX_N = 105;
  int MAX_K = 4;
  ll dp[2][MAX_N][MAX_K];
  dp[0][0][0] = 1;
  dp[1][0][0] = 1;
  
  rep(i, value.length() + 1)
  {
    
    rep(j, keta + 1)
    {
      rep(p, 2){
      	if(i < j)
        {
          dp[p][i][j] = 0;
        }
        else if(j == 0)
        {
          dp[p][i][j] = 1;
        }
        else{
          int x = i == 0 ? -1 : value[value.length()-i] - '0';
          if(p == 1){
            x = 9;
          }
          
          if(x == 0)
          {
              dp[p][i][j] = dp[p][i-1][j];
          }
          else
          {
            dp[p][i][j] = dp[p][i-1][j-1] + dp[1][i-1][j-1] * (x-1) + dp[1][i-1][j];
          }
        }
      }
    }
  }
  
  return dp[0][value.length()][keta];
}

int main()
{
  string n;
  int k;
  cin >> n >> k;
  cout << fixed << calc(n, k) << endl;
  return 0;
}
