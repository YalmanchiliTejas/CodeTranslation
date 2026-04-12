#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int dp[105][5][1005];
int main() {
  string S;
  int K;
  cin>>S>>K;
  int N=S.size();
  dp[0][0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<1000;k++){
        if(dp[i][j][k]==0){continue;}
        int lim=j?9:S[i]-'0';
        for(int d=0;d<lim+1;d++){
          if(d==0){(dp[i+1][j||(d<lim)][k]+=dp[i][j][k])%=mod;}
          else{(dp[i+1][j||(d<lim)][k+1]+=dp[i][j][k])%=mod;}
        }
      }
    }
  }
  cout<<(dp[N][0][K]+dp[N][1][K])<<endl;
  return 0;  
}