// Last Change: 07/20/2019 23:03:49.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max();

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (auto &&e : A) {
    cin >> e;
  }

  vector<vector<ll>> dp(2, vector<ll>());
  dp[0].push_back(-1);
  dp[1].push_back(INF);
  for (ll i = 0; i < N; ++i) {
    ll tar = A[i], pos;
    // lower_bound
    ll left, right, center, tmp;
    left = dp.size() - 2;
    right = 0;
    while (left > right) {
      center = left - (left - right) / 2;
      tmp = dp[center][0];
      if (tmp < tar) {
        left = center - 1;
      } else {
        right = center;
      }
    }
    pos = right + 1;

    if (dp[pos][0] == INF) {
      dp.push_back(vector<ll>());
      dp[pos + 1].push_back(INF);
    }
    dp[pos].push_back(tar);
    dp[pos][0] = tar;
  }
  /*
    for (auto &&e : dp) {
      for (auto &&f : e) {
        if (f == INF) {
          cout << "INF ";
        } else {
          cout << f << ' ';
        }
      }
      cout << endl;
    }
  */
  cout << dp.size() - 2 << endl;
}
