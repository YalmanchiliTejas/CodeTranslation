#include <bits/stdc++.h>
//#include "util.h"

#define ll long long
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr char nl = '\n';
  const int mod = 1e9 + 7;

  int N = 0;
  cin >> N;
  vector<ll> arr(N);
  for (int i = 0; i < N; ++i) {
    ll a = 0;
    cin >> a;
    arr[i] = a;
  }

  vector<vector<ll>> dp(N, vector<ll>(N, 0));
  for (int i = 1; i <= N; ++i) {
    for (int l = 0; l <= N - i; ++l) {
      int r = l + i - 1;
      ll choose_left = (l < N - 1 ? arr[l] - dp[l + 1][r] : arr[l]);
      ll choose_right = (r > 0 ? arr[r] - dp[l][r - 1] : arr[r]);
      dp[l][r] = max(choose_left, choose_right);
    }
  }

  cout << dp[0][N - 1] << nl;

  return 0;
}
