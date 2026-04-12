#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  ll dp[n + 1][k + 2][2] = {};
  dp[0][0][0] = 1;
  rep(i, n) rep(j, k + 1) {
    int d = s[i] - '0';
    int nj = d == 0 ? j : (j + 1);
    dp[i + 1][nj][0] += dp[i][j][0];
    if(d > 0) {
      dp[i + 1][j + 1][1] += dp[i][j][0] * (d - 1);
      dp[i + 1][j][1] += dp[i][j][0];
    }
    dp[i + 1][j + 1][1] += dp[i][j][1] * 9;
    dp[i + 1][j][1] += dp[i][j][1];
  }
  cout << dp[n][k][0] + dp[n][k][1] << endl;
}