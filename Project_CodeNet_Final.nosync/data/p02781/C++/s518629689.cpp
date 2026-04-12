#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;

int main() {
  string S; cin >> S;
  int K; cin >> K;
  int L = S.size();
  // dp[i : 決めた桁数][j : 未満フラグ][k : 0 でない個数]
  vvvl dp(110, vvl(2, vl(110, 0)));
  dp.at(0).at(0).at(0) = 1;
  for (int i = 0; i < L; i++) {
    int D = S.at(i) - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 101; k++) {
        for (int d = 0; d <= (j ? 9 : D); d++) {
          if (d == 0) dp.at(i+1).at(j || (d < D)).at(k) += dp.at(i).at(j).at(k);
          else dp.at(i+1).at(j || (d < D)).at(k+1) += dp.at(i).at(j).at(k);
        }
      }
    }
  }
  cout << dp.at(L).at(0).at(K) + dp.at(L).at(1).at(K) << endl;
}