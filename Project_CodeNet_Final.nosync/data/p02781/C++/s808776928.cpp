#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[2][110][5]={0};
  
int main()
{
  string S;
  cin >> S;
  int K;
  cin >> K;
  dp[0][0][0]=1;
  dp[0][0][1]=(S.at(0)-'0'-1);
  dp[1][0][0]=0;
  dp[1][0][1]=1;
  REP(i,S.size()-1){
    REP(j,K+1){
      dp[0][i+1][j]+=dp[0][i][j];
      if(j+1<=K){
        dp[0][i+1][j+1]+=dp[0][i][j]*9;
      }
      if(S.at(i+1)!='0'){
        dp[0][i+1][j]+=dp[1][i][j];
        if(j+1<=K){
          dp[0][i+1][j+1]+=(S.at(i+1)-'0'-1)*dp[1][i][j];
          dp[1][i+1][j+1]+=dp[1][i][j];
          dp[1][i+1][j]+=0;
        }
      }else{
        dp[1][i+1][j+1]+=0;
        dp[1][i+1][j]+=dp[1][i][j];
      }
    }
  }

  cout << dp[1][S.size()-1][K]+dp[0][S.size()-1][K] << endl;
}