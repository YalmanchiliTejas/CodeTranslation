#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b) { return b?gcd(b,a%b):a;}
long long lcm(long long a, long long b) { return a/gcd(a,b)*b;}

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int dp[105][4][2];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int K;
  cin >> K;
  dp[0][0][0] = 1;
  rep(i,n)rep(j,4)rep(k,2) {
    int nd = s[i]-'0';
    rep(d,10) {
      int ni = i+1, nj = j, nk = k;
      if (d != 0) nj++;
      if (nj > K) continue;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
  return 0;



  // string s;
  // cin >> s;
  // int k;
  // cin >> k;
  // int dp[s.size()][k + 1][2];
  // rep(i, s.size() + 1) rep(j, k + 1) rep(h, 2) dp[i][j][h] = 0;
  // dp[0][0][0] = 1;

  // for (int i = 0; i < s.size(); i++) {
  //   int x = s[i] - '0';
  //   int ni = i + 1;

  //   rep (j, k + 1) {
  //     rep (a, 10) {
  //       int nj = j;
  //       if (a != 0) nj = j + 1;
  //       if (nj > k) continue;

  //       rep (h, 2) {
  //         int nk = 0;
  //         if ((x == a && h == 1) || (x == a && i == 0)) nk = 1;
  //         else if ((h == 1 && a > x) || (i == 0 && a > x)) break;
  //         dp[ni][nj][nk] += dp[i][j][h];
  //       }
  //     }
  //   }
  // }

  // int ans = dp[s.size()][k][0] + dp[s.size()][k][1];
  // cout << ans << endl;
  // return 0;
}