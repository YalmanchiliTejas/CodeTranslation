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

const int INF = 2000000000;

int main() {
  int N;
  cin >> N;
  int a[100000];
  int dp[100000];
  rep(i, N) {
    dp[i] = INF;
  }
  rep(i, N) {
    cin >> a[N-1-i];
  }
  rep(i, N) {
    int key = a[i];
    int ind = upper_bound(dp, dp+N, key) - dp;
    dp[ind] = key;
  }
  int ans = lower_bound(dp, dp+N, INF) - dp;
  cout << ans << endl;
  return 0;
}