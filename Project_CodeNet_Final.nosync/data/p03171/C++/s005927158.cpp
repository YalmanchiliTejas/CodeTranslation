#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long int INF = 1LL<<60;
const long long int mod = 1e9 + 7;

long long int rec(vector<vector<long long int>> &dp, int i, int j, vector<int> &a) {
  if(dp[i][j] != INF) return dp[i][j];

  int N = dp.size() - 1;

  int ops = N - (j - i + 1);
  if(ops%2 == 0) {
    dp[i][j] = max(a[i] + rec(dp, i+1, j, a), a[j] + rec(dp, i, j-1, a));
    return dp[i][j];
  } else {
    dp[i][j] = min(rec(dp, i+1, j, a) - a[i], rec(dp, i, j-1, a) - a[j]);
    return dp[i][j];
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N+1);
  for(int i=1; i<=N; i++) {
    cin >> a.at(i);
  }

  // x-y will be stored in dp
  vector<vector<long long int>> dp(N+1, vector<long long int>(N+1, INF));
  // initialize
  for(int i=1; i<=N; i++) {
    if(N%2 == 1) {
      dp[i][i] = a[i];
    } else {
      dp[i][i] = -a[i];
    }
  }

  long long int res = rec(dp, 1, N, a);

  cout << res << endl;
  return 0;
}