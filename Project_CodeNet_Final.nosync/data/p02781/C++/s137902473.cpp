#include <bits/stdc++.h>
using namespace std;
int main(){
  string N;
  cin >> N;
  int K;
  cin >> K;
  int L = N.size();
  vector<int> n(L);
  for (int i = 0; i < L; i++){
    n[i] = N[i] - '0';
  }
  vector<vector<vector<long long>>> dp(L + 1, vector<vector<long long>>(2, vector<long long>(K + 2, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < L; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k <= K; k++){
        for (int d = 0; d <= (j ? 9 : n[i]); d++){
          dp[i + 1][j | d < n[i]][d == 0 ? k : k + 1] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[L][0][K] + dp[L][1][K] << endl;
}