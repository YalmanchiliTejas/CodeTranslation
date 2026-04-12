#include "bits/stdc++.h"
#define rep(i, a) for (int i = 0; i < (a); ++i)
using namespace std;
typedef long long ll;

const ll INF = 100100100100;

int n;
vector<vector<ll>> dp(3010, vector<ll>(3010, INF));
vector<int> a;

ll rec(int i, int j) {
  if (dp[i][j] != INF) return dp[i][j];
  if (i == j) return dp[i][j] = (n % 2 == 1 ? a[i] : -a[i]);
  ll left = rec(i + 1, j);
  ll right = rec(i, j - 1);
  if ((n - (j - i)) % 2)
    return dp[i][j] = max(a[i] + left, a[j] + right);
  else
    return dp[i][j] = min(-a[i] + left, -a[j] + right);
}

int main() {
  cin >> n;
  a.resize(n);
  rep(i, n) cin >> a[i];
  cout << rec(0, n - 1) << endl;
}