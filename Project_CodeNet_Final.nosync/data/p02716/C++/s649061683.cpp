#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
#define fi first
#define se second
using namespace std;
using lint = long long;
using uint = unsigned int;
using ulint = unsigned long long;
using ldouble = long double;
using pii = pair<int, int>;
using pli = pair<lint, lint>;
using pdd = pair<double, double>;
using pld = pair<ldouble, ldouble>;
using v1i = vector<int>;
using v1li = vector<lint>;
using v2i = vector<vector<int>>;
using v2li = vector<vector<lint>>;
using v3i = vector<vector<vector<int>>>;
using v3li = vector<vector<vector<lint>>>;
using v1b = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<vector<vector<bool>>>;
using v1c = vector<char>;
using v2c = vector<vector<char>>;
using v3c = vector<vector<vector<char>>>;
constexpr lint mod1 = 1e9+7;
constexpr lint mod2 = 998244353;

int main() {
  int n; lint a;
  cin >> n;
  v1i v(n);
  rep(i, n) cin >> v[i];
  v2li dp(n+1, v1li(4, -1*1e15)); dp[0][0] = 0; dp[1][0] = v[0]; dp[2][1] = v[1]; if(n > 2) dp[3][2] = v[2];
  rep(i, n-2){
    if(i % 2 == 0){
      dp[i+3][0] = dp[i+1][0] + v[i+2];
      dp[i+3][2] = max(dp[i+3][2], max(dp[i+1][2] + v[i+2], dp[i][1] + v[i+2]));
      if(i > 0) dp[i+3][2] = max(dp[i+3][2], dp[i-1][0] + v[i+2]);
    }
    else dp[i+3][1] = max(dp[i+1][1] + v[i+2], dp[i][0] + v[i+2]);
  }
  if(n % 2 == 0) a = max(dp[n][1], dp[n-1][0]);
  else a = max(dp[n][2], max(dp[n-1][1], dp[n-2][0]));
  cout << a << endl;
  return 0;
}