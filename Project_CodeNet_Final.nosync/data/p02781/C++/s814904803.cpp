#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
  for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
  for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
//#define endl "\n"
#define ciosup \
  cin.tie(0);  \
  ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 1e9 + 7LL;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    is >> v[i];
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size() - 1; ++i) {
    os << v[i] << " ";
  }
  if (v.size() > 0) {
    os << v[v.size() - 1] << endl;
  }
  return os;
}

int main() {
  string n;
  int k;
  cin >> n >> k;
  int sz =n.size();
  vector<vector<vll>> dp(sz + 1, vector<vll>(2, vll(k+1, 0)));
  dp[0][0][0] = 1;
  REP(i, sz) {
    if (n[i] == '0'){
      REP(l,k+1) dp[i + 1][0][l] = dp[i][0][l];
    } else {
      REP(l, k) dp[i + 1][0][l+1] = dp[i][0][l];
      REP(l, k + 1) dp[i + 1][1][l] += dp[i][0][l];
      int num = n[i] - '0' - 1;
      REP(l, k) dp[i + 1][1][l+1] += num*dp[i][0][l];
    }
    REP(l, k) dp[i + 1][1][l + 1] += 9 * dp[i][1][l];
    REP(l, k + 1) dp[i + 1][1][l] += dp[i][1][l];
  }
  ll ans = 0;
  REP(i,2){
     ans += dp[sz][i][k];
  }
  cout << ans << endl;
}