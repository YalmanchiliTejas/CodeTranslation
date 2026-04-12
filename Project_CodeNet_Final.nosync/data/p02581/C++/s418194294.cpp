#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
void chmax(int& a, int b) { a = max(a, b);}

int dp[2005][2005];

int main() {
  int n;
  cin >> n;
  int n3 = n*3;
  vector<int> A(n3);
  rep(i,n3) cin >> A[i], --A[i];
  int m = n+1;
  rep(i,m)rep(j,m) dp[i][j] = -1e9;
  auto upd = [&](int i, int j, int x) {
    chmax(dp[i][j], x);
    chmax(dp[j][i], x);
    chmax(dp[i][n], x);
    chmax(dp[n][i], x);
    chmax(dp[n][j], x);
    chmax(dp[j][n], x);
    chmax(dp[n][n], x);
  };
  upd(A[0],A[1],0);

  int base = 0;
  for (int ai = 2; ai < n3-1; ai += 3) {
    int x = A[ai], y = A[ai+1], z = A[ai+2];
    if (x == y && y == z) {
      ++base;
      continue;
    }
    vector<tuple<int,int,int>> q;
    rep(ri,3) {
      {
        rep(a,m) {
          int now = dp[a][n];
          if (y == z) chmax(now, dp[a][y]+1);
          q.emplace_back(a,x,now);
        }
      }
      {
        int now = max(dp[n][n],dp[z][z]+1);
        q.emplace_back(x,y,now);
      }
      swap(x,y); swap(y,z);
    }

    for (auto t : q) {
      int i, j, x;
      tie(i,j,x) = t;
      upd(i,j,x);
    }
  }

  int ans = dp[n][n];
  int l = A[n3-1];
  chmax(ans, dp[l][l]+1);
  ans += base;
  cout << ans << endl;
  return 0;
}