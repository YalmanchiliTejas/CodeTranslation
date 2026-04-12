#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  int K; cin >> K;
  int L = S.size();
  // dp[i][j] := 左から i 桁決めて、0 でない数を j 個含む
  vector<vector<long long>> dp0(L+1, vector<long long>(5));
  vector<vector<long long>> dp1(L+1, vector<long long>(5));
  dp0.at(0).at(0) = 1;
  for (int i = 0; i < L; i++) {
    // j = 4, 5, ... からの遷移は不要
    for (int j = 0; j < 4; j++) {
      // 未満フラグが立っていない場合 (dp0[i][j] からの遷移)
      int D = S.at(i) - '0';
      for (int d = 0; d <= D; d++) {
        int nj = j;
        if (d != 0) nj++;
        if (d < D) {  // 未満フラグが立つ
          dp1.at(i+1).at(nj) += dp0.at(i).at(j);
        }
        else {
          dp0.at(i+1).at(nj) += dp0.at(i).at(j);
        }
      }
      // 未満フラグが立っている場合 (dp1[i][j] からの遷移)
      for (int d = 0; d <= 9; d++) {
        int nj = j;
        if (d != 0) nj++;
        dp1.at(i+1).at(nj) += dp1.at(i).at(j);
      }
    }
  }
  cout << dp0.at(L).at(K) + dp1.at(L).at(K) << endl;
}