#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string N;
  cin >> N;
  ll L = N.size();
  ll K;
  cin >> K;
  vector<vector<ll>> dp(K + 1, vector<ll>(2, 0));
  dp.at(0).at(0) = 1;
  for (ll i = 0; i < L; ++i) {
    vector<vector<ll>> temp(K + 1, vector<ll>(2, 0));
    for (ll j = 0; j < K; ++j) {
      if (N.at(i) == '0') {
        temp.at(j).at(0) += dp.at(j).at(0);
        temp.at(j + 1).at(1) += dp.at(j).at(1) * 9;
        temp.at(j).at(1) += dp.at(j).at(1);
      }
      else {
        temp.at(j + 1).at(0) += dp.at(j).at(0);
        temp.at(j + 1).at(1) += dp.at(j).at(1) * 9 + dp.at(j).at(0) * (ll)(N.at(i) - '1');
        temp.at(j).at(1) += dp.at(j).at(1) + dp.at(j).at(0);
      }
    }
    temp.at(K).at(0) += dp.at(K).at(0);
    temp.at(K).at(1) += dp.at(K).at(1);
    dp = temp;
    // for (ll i = 0; i <= K; ++i) {
    //   for (ll j = 0; j < 2; ++j) {
    //     cout << dp.at(i).at(j) << " ";
    //   }
    //   cout << "\n";
    // }
  }
  cout << dp.at(K).at(0) + dp.at(K).at(1) << "\n";
}
