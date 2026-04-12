#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll dp[2][3001][3001];
int A[3001];
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  for(int i = 0;i < n;i++)
    cin >> A[i];

    for(int j = 1;j <= n;j++){
      for(int k = 0;k + j - 1 < n;k++){
        for(int i = 0;i < 2;i++){
        int s = k, e = k + j - 1;
        if(j == 1){
          dp[i][s][e] = (i == 0 ? A[s] : -A[s]);
        }else{
          if(i == 0)
            dp[0][s][e] = max(dp[1][s + 1][e] + A[s], dp[1][s][e - 1] + A[e]);
          else
            dp[1][s][e] = min(dp[0][s + 1][e] - A[s], dp[0][s][e - 1] - A[e]);
        }
      }
    }
  }
  cout << dp[0][0][n - 1];
  return 0;
}
