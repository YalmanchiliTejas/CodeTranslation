#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  string N;
  cin >> N;
  ll K;
  cin >> K;
  ll len = N.size();
  vector<vector<vector<ll>>> dp(len + 1, vector<vector<ll>>(K + 2, vector<ll>(2, 0)));
  ll cnt = 0;
  ll temp = -1;
  while (cnt <= K && (temp != len)) {
    temp += 1;
    dp.at(temp).at(cnt).at(0) = 1;
    if (N[temp] == '0') {
      continue;
    }
    cnt += 1;
  }
  for (ll i = 0; i < len; ++i) {
    for (ll j = 0; j <= K; ++j) {
      dp.at(i + 1).at(j + 1).at(1) += dp.at(i).at(j).at(1) * 9;
      dp.at(i + 1).at(j).at(1) += dp.at(i).at(j).at(1);

      if (N[i] != '0') {
        dp.at(i + 1).at(j).at(1) += dp.at(i).at(j).at(0);
        dp.at(i + 1).at(j + 1).at(1) += dp.at(i).at(j).at(0) * (N[i] - '0' - 1);
      }
    }
  }
  // for (ll i = 0; i < len + 1; ++i) {
  //   for (ll j = 0; j < K + 1; ++j) {
  //     for (ll k = 0; k < 2; ++k) {
  //       cout << dp.at(i).at(j).at(k) << ' ';
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  //   cout << endl;
  // }
  ll ans = 0;
  for (ll i = 0; i < 2; ++i) {
    ans += dp.at(len).at(K).at(i);
  }
  cout << ans << endl;
}
