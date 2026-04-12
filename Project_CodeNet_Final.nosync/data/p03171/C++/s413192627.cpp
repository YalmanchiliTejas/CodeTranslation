#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 3005;
const ll INF = 1e15;

int n, a[N];

ll dp[N][N];

ll rec(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i == j) return dp[i][j] = a[i];
  return dp[i][j] = max(a[i] - rec(i+1, j), a[j] - rec(i, j-1));
}

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];

  rep(i, n+1) rep(j, n+1) dp[i][j] = -1;
  cout << rec(0, n-1) << endl;
  return 0;
}