#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  string N;
  int K;
  cin >> N >> K;
  int n[100];
  rep(i, N.size()) {
    n[i] = N[i] - '0';
  }
  int l = N.size();
  int dp[101][2][100] = {0};
  // cout << 1 << endl;
  dp[0][0][0] = 1;

  rep(i, l) {
    rep(smaller, 2) {
      rep(j, 10) {
        for(int x = 0; x <= (smaller ? 9 : n[i]); x++) {
          if(x == 0) {
            dp[i+1][smaller || x < n[i]][j] += dp[i][smaller][j];
          } else {
            dp[i+1][smaller || x < n[i]][j+1] += dp[i][smaller][j];
          }
        }
      }
    }
  }

  // cout << dp[0][1][0] << endl;
  cout << dp[l][0][K] + dp[l][1][K] << endl;
  return 0;
}