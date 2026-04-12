#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define maxs(x,y) x = max(x,y)

int main() {
  int n;
  cin >> n;
  int n3 = n*3;
  vector<int> A(n3);
  rep(i,n3) cin >> A[i], --A[i];
  const int INF = 1e9;
  int m = n+1;
  vector<vector<int>> dp(m,vector<int>(m,-INF));
  int base = 0;

  auto upd = [&](int i, int j, int x) {
    maxs(dp[i][j], x);
    maxs(dp[j][i], x);
    maxs(dp[i][n], x);
    maxs(dp[n][i], x);
    maxs(dp[n][j], x);
    maxs(dp[j][n], x);
    maxs(dp[n][n], x);
  };
  upd(A[0],A[1],0);

  rep(ai,n-1) {
    // rep(i,m)rep(j,m) printf("%d %d : %d\n", i,j,dp[i][j]);
    int a = A[ai*3+2], b = A[ai*3+3], c = A[ai*3+4];
    vector<int> p = dp[n];
    vector<int> pa = dp[a];
    vector<int> pb = dp[b];
    vector<int> pc = dp[c];
    int pp = dp[n][n];
    int paa = dp[a][a];
    int pbb = dp[b][b];
    int pcc = dp[c][c];
    if (a == b && b == c) {
      base++;
      rep(i,m) {
        p[i]--;
        pa[i]--;
        pb[i]--;
        pc[i]--;
      }
      pp--;
      paa--; pbb--; pcc--;
    }
    rep(ri,3) {
      { // i,j,a,b,c -j,b,c-> i,a
        rep(i,m) {
          int now = p[i];
          if (b == c) maxs(now, pb[i]+1);
          upd(i,a,now);
        }
      }
      { // i,j,a,b,c -i,j,c-> a,b
        int now = max(pp, pcc+1);
        upd(a,b,now);
      }
      swap(a,b); swap(b,c);
      swap(pa,pb); swap(pb,pc);
      swap(paa,pbb); swap(pbb,pcc);
    }
    // rep(i,m)rep(j,m) printf("%d %d : %d\n", i,j,dp[i][j]);
  }

  int ans = 0;
  rep(i,m)rep(j,m) {
    int now = dp[i][j];
    if (i == A[n3-1] && i == j) ++now;
    maxs(ans, now);
  }
  ans += base;
  cout << ans << endl;
  return 0;
}