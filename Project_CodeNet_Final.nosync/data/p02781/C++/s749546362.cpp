#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int K;
  cin>>K;

  int N=S.size();
  vector<vector<int64_t>> dp0(N+1,vector<int64_t>(4,0));
  vector<vector<int64_t>> dp1(N+1,vector<int64_t>(4,0));
  //初期値
  dp0[0][0]=1;
  for(int i=1;i<N;++i) dp0[i][0]=0;
  dp1[0][0]=0;
  for(int i=1;i<N;++i) dp1[i][0]=1;
  


  for(int i=0;i<N;++i){
    for(int j=1;j<=K;++j){
      int a=S[i]-'0';
      if(a==0){
        dp0[i+1][j]=dp0[i][j];
        dp1[i+1][j]=9*dp1[i][j-1]+dp1[i][j];
      }
      else{
        dp0[i+1][j]=dp0[i][j-1];
        dp1[i+1][j]=(a-1)*dp0[i][j-1]+dp0[i][j]+9*dp1[i][j-1]+dp1[i][j];
      }
    }
  }

  cout<<dp0[N][K]+dp1[N][K]<<endl;
}
