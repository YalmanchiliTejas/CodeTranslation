#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned int uint;
typedef unsigned long long ulint;
typedef long double ldouble;
using pii = pair<int, int>;
using pli = pair<lint, lint>;
using pdd = pair<double, double>;
using pld = pair<ldouble, ldouble>;
constexpr lint mod1 = 1e9+7;

int main() {
  string s; int l;
  cin >> s >> l;
  vector<int> n(s.size());
  rep(i, s.size()) n[i] = s[i] - '0';
  vector<vector<vector<ulint>>> dp(s.size()+1, vector<vector<ulint>>(2, vector<ulint>(s.size()+1, 0)));
  dp[0][1][0] = 1;
  rep(i, s.size()){
    rep(j, 10){
      if(j == 0) rep(k, s.size()+1) dp[i+1][0][k] += dp[i][0][k];
      else rep(k, s.size()+1) dp[i+1][0][min(k+1, (int)s.size())] += dp[i][0][k];      
    }
    rep(j, 10){
      if(j < n[i]){
        if(j == 0) rep(k, s.size()+1) dp[i+1][0][k] += dp[i][1][k];
        else rep(k, s.size()+1) dp[i+1][0][min(k+1, (int)s.size())] += dp[i][1][k];
      }
      else if(j == n[i]){
        if(j == 0) rep(k, s.size()+1) dp[i+1][1][k] += dp[i][1][k];
        else rep(k, s.size()+1) dp[i+1][1][min(k+1, (int)s.size())] += dp[i][1][k];
        break;
      }
    }
  }
  cout << dp[s.size()][0][l] + dp[s.size()][1][l] << endl;
  return 0;
}