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
  dp.at(0).at(0).at(0) = 1;
  for (ll i = 0; i < len; ++i) {
    for (ll j = 0; j <= K; ++j) {
      if (N[i] == '0') {
        dp.at(i + 1).at(j).at(0) = dp.at(i).at(j).at(0);
      }
      else {
        dp.at(i + 1).at(j + 1).at(0) = dp.at(i).at(j).at(0);
      }
      dp.at(i + 1).at(j + 1).at(1) += dp.at(i).at(j).at(1) * 9;
      dp.at(i + 1).at(j).at(1) += dp.at(i).at(j).at(1);

      if (N[i] != '0') {
        dp.at(i + 1).at(j).at(1) += dp.at(i).at(j).at(0);
        dp.at(i + 1).at(j + 1).at(1) += dp.at(i).at(j).at(0) * (N[i] - '0' - 1);
      }
    }
  }
  ll ans = 0;
  for (ll i = 0; i < 2; ++i) {
    ans += dp.at(len).at(K).at(i);
  }
  cout << ans << endl;
}
