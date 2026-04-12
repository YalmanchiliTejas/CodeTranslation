#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1e9+7;

int dp[10005][2][101];

int main(){
  string s;
  cin >> s;
  int d;
  cin >> d;
  int n = s.size();
  dp[0][0][0] = 1;
  rep(i,n) {
    const int P = s[i] - '0';
    rep(j,2) {
      rep(k,d) {
        for (int p = 0; p <= (j ? 9 : P); p++) {
          (dp[i+1][j || (p<P)][(k+p)%d] += dp[i][j][k]) %= mod;
        }
      }
    }
  }
  int res = (dp[n][0][0] + dp[n][1][0] - 1 + mod)%mod;
  cout << res << endl;//0の場合を引く
  return 0;
}