#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;

int main() {
  int MOD = 1000000007;
  string K; cin >> K;
  int D; cin >> D;
  int L = K.size();
  vvvl dp(10010, vvl(2, vl(D, 0)));
  dp.at(0).at(0).at(0) = 1;
  for (int i = 0; i < L; i++) {
    int Digit = K.at(i) - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < D; k++) {
        for (int d = 0; d <= (j ? 9 : Digit); d++) {
          dp.at(i+1).at(j || (d < Digit)).at((k + d) % D) += dp.at(i).at(j).at(k);
          dp.at(i+1).at(j || (d < Digit)).at((k + d) % D) %= MOD;
        }
      }
    }
  }
  cout << (dp.at(L).at(0).at(0) + dp.at(L).at(1).at(0) - 1 + MOD) % MOD << endl;
}