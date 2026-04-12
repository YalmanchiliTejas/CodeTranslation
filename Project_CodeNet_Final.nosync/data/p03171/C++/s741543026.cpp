#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int dp[3002][3002];
//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  if(N==1){cout<<v[0]<<endl;return 0;}
  if(N%2==0){
    for(int i=0;i<=N-2;i++)dp[i][i+1]=abs(v[i]-v[i+1]);
    for(int j=3;j<=N;j++){
      for(int i=0;i<=N-j;i++){
        if(j%2)dp[i][i+j-1]=min(dp[i+1][i+j-1]-v[i],dp[i][i+j-1-1]-v[i+j-1]);
        else dp[i][i+j-1]=max(dp[i+1][i+j-1]+v[i],dp[i][i+j-1-1]+v[i+j-1]);
      }
    }
  }
  else{
    for(int i=0;i<=N-2;i++)dp[i][i+1]=(-1)*abs(v[i]-v[i+1]);
    for(int j=3;j<=N;j++){
      for(int i=0;i<=N-j;i++){
        if(j%2)dp[i][i+j-1]=max(dp[i+1][i+j-1]+v[i],dp[i][i+j-1-1]+v[i+j-1]);
        else dp[i][i+j-1]=min(dp[i+1][i+j-1]-v[i],dp[i][i+j-1-1]-v[i+j-1]);
      }
    }
  }
  /*
  for(int i=0;i<=4;i++){
    for(int j=0;j<=4;j++)cout<<dp[i][j]<<" ";cout<<endl;
  }
  */
  cout<<dp[0][N-1]<<endl;
}
