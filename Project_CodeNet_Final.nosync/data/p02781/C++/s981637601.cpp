#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int dp[105][4][2];

int main() {
  string s; int K;
  cin >> s >> K;
  int n = len(s);
  dp[0][0][0] = 1;
  rep(i,0,n) rep(j,0,4) rep(k,0,2) {
    int d = s[i]-'0';
    rep(nd,0,10) {
      int ni = i+1, nj = j, nk = k;
      if (nd != 0) nj++;
      if (nj > K) continue;
      if (k == 0) {
        if (nd > d) continue;
        else if (nd < d) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
  return 0;
}
