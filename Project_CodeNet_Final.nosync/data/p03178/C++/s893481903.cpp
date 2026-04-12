#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int main(){
  string K;
  cin >> K;
  int D;
  cin >> D;
  int L = K.size();
  vector<int> N(L);
  for (int i = 0; i < L; i++){
    N[i] = K[i] - '0';
  }
  vector<vector<vector<long long>>> dp(L + 1, vector<vector<long long>>(2, vector<long long>(D, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < L; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < D; k++){
        for (int d = 0; d <= (j ? 9 : N[i]); d++){
          dp[i + 1][j | d < N[i]][(k + d) % D] = (dp[i + 1][j | d < N[i]][(k + d) % D] + dp[i][j][k]) % MOD;
        }
      }
    }
  }
  cout << (dp[L][0][0] + dp[L][1][0] + MOD - 1) % MOD;
}