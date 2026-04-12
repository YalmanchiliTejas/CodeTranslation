#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

ll N;

ll dp[3005][3005];

// 0  0  0  0  0  0  0
// 0  0  0  0  0  0  0
// 0  0  0  0  0  0  0
// 0  0  0  0  0  0  0
// 0  0  0  0  0  0  0
// 0  0  0  0  0  0  0

// 0 -4  0  0  0  0  0
// 0  0 -2  0  0  0  0
// 0  0  0 -9  0  0  0
// 0  0  0  0 -7  0  0
// 0  0  0  0  0 -1  0
// 0  0  0  0  0  0 -5

// 0 -4  2  0  0  0  0
// 0  0 -2  7  0  0  0
// 0  0  0 -9  2  0  0
// 0  0  0  0 -7  6  0
// 0  0  0  0  0 -1  4
// 0  0  0  0  0  0 -5
// 0  0  0  0  0  0  0

// 0 -4  2 -7  0  0  0
// 0  0 -2  7  0  0  0
// 0  0  0 -9  2 -3  0
// 0  0  0  0 -7  6 -3
// 0  0  0  0  0 -1  4
// 0  0  0  0  0  0 -5

// 0 -4  2 -7  4  0  0
// 0  0 -2  7  0  1  0
// 0  0  0 -9  2 -3  6
// 0  0  0  0 -7  6 -3
// 0  0  0  0  0 -1  4
// 0  0  0  0  0  0 -5

// 0 -4  2 -7  4 -3  0
// 0  0 -2  7  0  1 -4
// 0  0  0 -9  2 -3  6
// 0  0  0  0 -7  6 -3
// 0  0  0  0  0 -1  4
// 0  0  0  0  0  0 -5

// 0 -4  2 -7  4 -3  2
// 0  0 -2  7  0  1 -4
// 0  0  0 -9  2 -3  6
// 0  0  0  0 -7  6 -3
// 0  0  0  0  0 -1  4
// 0  0  0  0  0  0 -5

void show_table() {
  for (ll i = 0; i <= N; i++) {
    for (ll j = 0; j <= N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "" << endl;
  }
  cout << "" << endl;
}

int main() {
  fill(dp[0], dp[3005], 0);
  // std::cout << std::fixed << std::setprecision(10);
  scanf("%lld", &N);

  vector<ll> list(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list[i] = v;
  }

  for (ll i = 0; i < N; i++) {
    dp[i][i] = 0;
  }

  for (ll rest = 0; rest < N; rest++) {
    // show_table();
    for (ll i = 0; i < (N - rest); ++i) {
      ll j = i + (rest + 1);
      bool first_turn = (N - rest) % 2 == 1;  // 注意
      if (first_turn) {
        ll val1 = dp[i + 1][j] + list[i];      // 左をとる
        ll val2 = dp[i][j - 1] + list[j - 1];  // 右をとる
        dp[i][j] = max(val1, val2);
      } else {
        ll val1 = dp[i + 1][j] - list[i];      // 左をとる
        ll val2 = dp[i][j - 1] - list[j - 1];  // 右をとる
        dp[i][j] = min(val1, val2);
      }
    }
  }

  // show_table();

  cout << dp[0][N] << endl;
}
