#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int32 n = s.size();
  int32 k;
  cin >> k;
  vector<vector<vector<int64>>> dp(n+1,vector<vector<int64>>(2,vector<int64>(k+1,0)));
  dp[0][0][0] = 1;
  REP(i,n){
    REP(j,k+1){
      if(s[i] == '0'){
        dp[i+1][0][j] += dp[i][0][j];
      }else{
        dp[i+1][1][j] += dp[i][0][j];
        if(j+1<=k){
          dp[i+1][0][j+1] += dp[i][0][j];
          dp[i+1][1][j+1] += dp[i][0][j] * (s[i] - '1');
        }        
      }
      dp[i+1][1][j] += dp[i][1][j];
      if(j+1<=k)
        dp[i+1][1][j+1] += dp[i][1][j] * 9;
    }
  }
  ANS(dp[n][0][k] + dp[n][1][k]);
  return 0;
}