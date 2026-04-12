#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll MOD = 998244353;

ll dp[3][3005][3005];

int main(){
  int N, S;
  cin >> N >> S;
  vector<int> v;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);
  }

  dp[0][0][0] = 1;
  rep(i,N){
    int a = v[i];
    rep(j,S+1){
      //使わない
      dp[0][i+1][j] += dp[0][i][j];
      dp[0][i+1][j] %= MOD;
      //Lにするが使わない
      dp[1][i+1][j] += dp[0][i][j];
      dp[1][i+1][j] %= MOD;
      //Lにして使う
      if(j+a<=S){
        dp[1][i+1][j+a] += dp[0][i][j];
        dp[1][i+1][j+a] %= MOD;
      }
      //LかつRにして使わない
      dp[2][i+1][j] += dp[0][i][j];
      dp[2][i+1][j] %= MOD;
      //LかつRにして使う
      if(j+a<=S){
        dp[2][i+1][j+a] += dp[0][i][j];
        dp[2][i+1][j+a] %= MOD;
      }

      //使わない
      dp[1][i+1][j] += dp[1][i][j];
      dp[1][i+1][j] %= MOD;
      //使う
      if(j+a<=S){
        dp[1][i+1][j+a] += dp[1][i][j];
        dp[1][i+1][j+a] %= MOD;
      }
      //Rにするが使わない
      dp[2][i+1][j] += dp[1][i][j];
      dp[2][i+1][j] %= MOD;
      //Rにして使う
      if(j+a<=S){
        dp[2][i+1][j+a] += dp[1][i][j];
        dp[2][i+1][j+a] %= MOD;
      }

      //使わない
      dp[2][i+1][j] += dp[2][i][j];
      dp[2][i+1][j] %= MOD;
    }
  }

  cout << dp[2][N][S] << endl;
  
  return 0;
}

