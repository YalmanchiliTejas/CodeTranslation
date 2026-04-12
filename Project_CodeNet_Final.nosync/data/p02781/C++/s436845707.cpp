#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

ll dp[105][4][2];

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  dp[0][0][0] = 1;
  rep(i, n) rep(j, 4/*現在の非0個数*/) rep(x, 2) {
    int next = s[i] - '0';
    rep(m, 10) {
      int nonZero = j + (m != 0); /*次の非ゼロ個数*/
      if (nonZero > k) continue;/* 最大まで0でない数字があらわれているにもかかわらず0でない数字を選択しようとした */
      if (x == 0) {
        if (m > next) {
          continue;
        } else if (m == next) {
          dp[i+1][nonZero][0] += dp[i][j][x];
        } else {
          dp[i+1][nonZero][1] += dp[i][j][x];
        }
      } else {
        dp[i+1][nonZero][x] += dp[i][j][x];
      }
    }
  }

  cout << dp[n][k][0] + dp[n][k][1] << endl;
}
