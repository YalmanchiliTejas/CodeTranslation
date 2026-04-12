#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int64_t dp[100005][5][105];
int main() {
  string S;
  int D;
  cin>>S>>D;
  int N=S.size();
  dp[0][0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<D;k++){
        if(dp[i][j][k]==0){continue;}
        int lim=j?9:S[i]-'0';
        for(int d=0;d<lim+1;d++){
          (dp[i+1][j||(d<lim)][(d+k)%D]+=dp[i][j][k])%=mod;
        }
      }
    }
  }
  cout<<(dp[N][0][0]+dp[N][1][0]-1+mod)%mod<<endl;
  return 0;  
}