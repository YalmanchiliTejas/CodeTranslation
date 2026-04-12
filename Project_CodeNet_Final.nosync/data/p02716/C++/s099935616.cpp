#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main() { 
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> dp(n + 1, 0);
  ll sum = a[0];
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) {
      dp[i] = max(a[i - 1] + dp[i - 2], sum);
    } else {
      dp[i] = max(a[i - 1] + dp[i - 2], dp[i - 1]);
      sum += a[i - 1];
    }
  }
  cout << dp[n] << endl;
  return 0;
} 