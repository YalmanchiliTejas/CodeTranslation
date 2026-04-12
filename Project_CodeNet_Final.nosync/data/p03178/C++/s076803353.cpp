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

int mod = 1000000007;
int dp[10010][101][2];

int main() {
  string s; int d;
  cin >> s >> d;
  int n = len(s);
  dp[0][0][0] = 1;
  rep(i,0,n) rep(j,0,d) rep(k,0,2) {
    int x = s[i]-'0';
    rep(nx,0,10) {
      int ni = i+1, nj = 0, nk = k;
      nj = (j + nx) % d;
      if (k == 0) {
        if (nx > x) continue;
        if (x > nx) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
      dp[ni][nj][nk] %= mod;
    }
  }
  int ans = (dp[n][0][0] + dp[n][0][1] - 1) % mod;
  ans = (ans + mod) % mod;
  cout << ans << endl;
  return 0;
}
