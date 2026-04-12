#include <bits/stdc++.h>
#define dummy 1e16
using namespace std;

long long n;
long long a[3005] = {0};
long long dp[3004][3005] = {0};

long long solve(long long l, long long r);

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) dp[i][j] = dummy;
  for(int i = 0; i < n; ++i) {
    if(n % 2)
      dp[i][i] = a[i];
    else
      dp[i][i] = -a[i];
  }
  cout << solve(0, n - 1) << endl;
  return 0;
}

long long solve(long long l, long long r) {
  if(dp[l][r] != dummy) return dp[l][r];
  long long ans = 0;
  if((r - l + 1) % 2 == n % 2)
    ans =
        max(a[l] + solve(l + 1, r), a[r] + solve(l, r - 1));
  else
    ans =
        min(solve(l + 1, r) - a[l], solve(l, r - 1) - a[r]);
  return dp[l][r] = ans;
}