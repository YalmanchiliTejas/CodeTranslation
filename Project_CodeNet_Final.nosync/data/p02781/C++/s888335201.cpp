#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[110][5],dp2[110][5];
signed main(){
  string N;
  int K;
  cin>>N>>K;
  dp2[0][0]=1;
  for(int i=0;i<N.size();i++){
    for(int j=0;j<=K;j++){
      dp[i+1][j]=dp[i][j]+(N[i]!='0'?dp2[i][j]:0);
      dp2[i+1][j]=(N[i]=='0'?dp2[i][j]:0);
    }
    for(int j=0;j<K;j++){
      dp[i+1][j+1]+=dp[i][j]*9+dp2[i][j]*max(N[i]-'1',0);
      dp2[i+1][j+1]+=(N[i]!='0'?dp2[i][j]:0);
    }
  }
  cout<<dp[N.size()][K]+dp2[N.size()][K]<<endl;
}