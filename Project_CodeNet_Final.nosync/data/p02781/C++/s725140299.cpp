#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

ll dp[105][2][5];

int main(){
  string N;
  int K;
  cin >> N >> K;

  dp[0][1][0] = 1;

  rep(i,N.size()){
    rep(j,2){
      rep(k,K+1){
        if(dp[i][j][k] == -1) continue;

        if(j==0){
          rep(x,10){
            dp[i+1][0][k+(x!=0?1:0)] += dp[i][j][k];
          }
        }else{
          rep(x,(N[i]-'0')+1){
            dp[i+1][x==(N[i]-'0')][k+(x!=0?1:0)] += dp[i][j][k];
          }
        }
      }
    }
  }

  cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
  
  return 0;
}

