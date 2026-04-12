#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S; cin >> S;
  ll N = S.size();
  ll K; cin >> K;
  vector<vector<vector<ll> > > dp(N+1, vector<vector<ll> >(K+1, vector<ll>(2, 0)));
  dp[0][0][0] = 1;
  REP(i, N) REP(j, K+1) REP(k, 2){
    ll cd = S[i] - '0';
    REP(d, 10){
      ll ni = i + 1, nj = j, nk = k;
      if(d != 0) nj++;
      if(nj > K) continue;
      if(k == 0){
        if(d > cd) continue;
        if(d < cd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  cout << dp[N][K][0] + dp[N][K][1] << endl;
}
