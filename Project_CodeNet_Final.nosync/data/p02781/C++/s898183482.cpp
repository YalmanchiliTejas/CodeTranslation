#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

const int MAX_DIGIT = 100;
long long dp[200][2][5];

int main() {
  string n;
  int k;
  cin >> n >> k;

  dp[0][0][0] = 1;

  rep(i, n.length()) {
    rep(j, 2) {
      rep(t, k + 1) {
        int c = n[i] - '0';  // i桁目
        rep(now, 10) {
          if (c < now && j == 0) continue;  // n以下でない場合は除く
          int jj = j;
          int tt = t;
          if (now != 0) tt++;
          if (now < c) jj = 1;  //これ以降は絶対に小さくなる
          dp[i + 1][jj][tt] += dp[i][j][t];
        }
      }
    }
  }
  ll ans = dp[n.length()][0][k] + dp[n.length()][1][k];
  cout << ans << endl;
}