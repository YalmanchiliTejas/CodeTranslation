#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
int char2int(char c) {
  return int(c-'0');
}
int main() {
  string N;
  int K;
  cin >> N >> K;
  int D = N.size();
  vector<vector<ll> > dp(D, vector<ll>((K+1)*2));
  dp[0][0] = 1;
  dp[0][0+K+1] = 0;
  dp[0][1] = char2int(N[0])-1;
  dp[0][1+K+1] = 1;
  REP(i, 1, D) {
    int tmp = char2int(N[i]);
    rep(k, K+1) {
      if(k) { // k>0
        dp[i][k] += dp[i-1][k-1] * 9;
        if(tmp) { // tmp>0
          dp[i][k] += dp[i-1][k+K] * (tmp-1);
          dp[i][k+K+1] += dp[i-1][k+K];
        }
      }
      dp[i][k] += dp[i-1][k];
      if(tmp) dp[i][k] += dp[i-1][k+K+1];
      else dp[i][k+K+1] += dp[i-1][k+K+1];
    }
  }
  cout << dp[D-1][K] + dp[D-1][2*K+1] << endl;
  return 0;
}
