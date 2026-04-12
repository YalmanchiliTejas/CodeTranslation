//
//  select_half.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;


int main(int argc, const char* argv[]) {

  int n;
  std::cin >> n;
  ll a[n];
  ll dp[n][2]; // 0: n/2, 1: n/2+1
  for (int i=0; i<n; i++) {
    std::cin >> a[i];
  }
  dp[2][0] = max(a[0], a[1]);

  if (n > 2) {
    dp[3][0] = max(dp[2][0], a[2]);
    dp[3][1] = a[0] + a[2];
    for (int i=4; i<=n; i++) {
      if (i%2 == 0) {
        dp[i][0] = max(dp[i-1][1], a[i-1] + dp[i-2][0]);
      }
      else {
        dp[i][0] = max(dp[i-1][0], a[i-1] + dp[i-2][0]);
      }
      if (i%2 == 1) {
        dp[i][1] = a[i-1] + dp[i-2][1];
      }
    }
  }
  // std::cout << dp[3][1] << std::endl;
  std::cout << dp[n][0] << std::endl;

  return 0;
}
