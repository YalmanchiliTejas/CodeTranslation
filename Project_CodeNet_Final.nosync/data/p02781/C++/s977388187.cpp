#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.size();
  ll dp[n + 1][k + 2][2] = {};
  rep(i, n + 1) rep(j, k + 1) rep(lt, 2) dp[i][j][lt] = 0;
  dp[0][0][0] = 1;
  rep(i, n) rep(j, k + 1) rep(lt, 2) {
    ll d = s[i] - '0';
    if(lt) {
      dp[i + 1][j + 1][1] += dp[i][j][lt] * 9;
      dp[i + 1][j][1] += dp[i][j][lt];
    } else {
      if(d > 0) {
        dp[i + 1][j + 1][0] += dp[i][j][lt];
        dp[i + 1][j + 1][1] += dp[i][j][lt] * (d - 1);
      }
      dp[i + 1][j][d != 0] += dp[i][j][lt];
    }
  }
  cout << dp[n][k][0] + dp[n][k][1] << endl;
}