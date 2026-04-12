#include <bits/stdc++.h>
#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

string N;
vector<ll> n;
ll dp[105][2][105];

main() {
  cin >> N;

  ll K;
  scanf("%lld", &K);

  //ベクターnを構成
  for (auto a : N) {
    n.push_back(a - '0');
  }
  int len = N.size();  // nの長さ

  dp[0][0][0] = 1;  //初期条件。他は0で初期化されている

  for (int i = 0; i < len; i++) {
    for (int smaller = 0; smaller < 2; smaller++) {
      for (int k = 0; k < 10; k++) {
        int lim = smaller ? 9 : n[i];
        for (int l = 0; l <= lim; l++) {
          ll next_smaller = smaller || l < lim;
          ll next_non0_num = k + (l != 0);
          dp[i + 1][next_smaller][next_non0_num] += dp[i][smaller][k];
        }
      }
    }
  }

  ll ans = dp[len][0][K] + dp[len][1][K];
  cout << ans << endl;

  return 0;
}
