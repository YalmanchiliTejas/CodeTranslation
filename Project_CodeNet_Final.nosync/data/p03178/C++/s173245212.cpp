#include <bits/stdc++.h>
using namespace std;

int main() {
  const int64_t mod = 1000000007;
  string s;
  cin >> s;
  int digit = s.size(), d;
  cin >> d;
  vector<int> k(digit);
  for (int i = 0; i < digit; i++) k.at(i) = s.at(i) - '0';
  vector<vector<vector<int64_t>>> dp(digit + 1,
                                     vector<vector<int64_t>>(d, vector<int64_t>(2)));
  dp.at(0).at(0).at(0) = 1;
  for (int i = 0; i < digit; i++) {
    for (int j = 0; j < d; j++) {
      for (int m = 0; m < 10; m++) {
        if (m < k.at(i)) {
          (dp.at(i + 1).at((j + m) % d).at(1) += dp.at(i).at(j).at(0)
            + dp.at(i).at(j).at(1)) %= mod;
        } else if (m == k.at(i)) {
          (dp.at(i + 1).at((j + m) % d).at(0) += dp.at(i).at(j).at(0)) %= mod;
          (dp.at(i + 1).at((j + m) % d).at(1) += dp.at(i).at(j).at(1)) %= mod;
        } else {
          (dp.at(i + 1).at((j + m) % d).at(1) += dp.at(i).at(j).at(1)) %= mod;
        }
      }
    }
  }
  cout << (dp.at(digit).at(0).at(0) + dp.at(digit).at(0).at(1) + mod - 1) % mod << endl;
}
