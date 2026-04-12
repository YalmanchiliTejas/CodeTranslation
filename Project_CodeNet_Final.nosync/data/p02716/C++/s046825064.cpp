#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  vector<vector<ll>> dp(N / 2 + 1, vector<ll>(2, -INF));
  dp.at(0).at(0) = 0;
  for (ll i = 0; i < N; ++i) {
    ll least, most;
    if (N % 2 == 0) {
      most = min(N / 2 - 1, (i + 1) / 2);
      least = min(N / 2 - 1, i / 2);
    }
    else {
      most = min(N / 2 - 1, (i + 1) / 2);
      least = max(0ll, (i - 1) / 2);
    }
    vector<vector<ll>> update(most - least + 2, vector<ll>(2, -INF));
    for (ll j = least; j <= most; ++j) {
      update.at(j - least + 1).at(1) = max(update.at(j - least + 1).at(1), max(dp.at(j + 1).at(1), dp.at(j).at(0) + A.at(i)));
      update.at(j - least).at(0) = max(update.at(j - least).at(0), max(dp.at(j).at(0), dp.at(j).at(1)));
    }
    for (ll j = 0; j < update.size(); ++j) {
      for (ll k = 0; k < 2; ++k) {
        dp.at(j + least).at(k) = max(update.at(j).at(k), dp.at(j + least).at(k));
      }
    }
  }
  cout << max(dp.at(N / 2).at(0), dp.at(N / 2).at(1)) << "\n";
}
