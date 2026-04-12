#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;
const int MAXN = 1000;
const int MAXK = 4;
int dp[MAXN][MAXK][2];

int main() {
  string s;
  cin >> s;
  int K;
  cin >> K;
  int n = s.length();
  dp[0][0][0] = 1;

  rep(i, n) rep(j, 4) rep(k, 2)  {
    int c = s[i] - '0';
    
    rep(l, 10) {
      int ni = i + 1, nj = j, nk = k;

      if (l != 0) nj++;
      if (nj > K) continue;

      if (k == 0) {
        if (l < c) nk = 1;
        else if (l > c) break;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
}