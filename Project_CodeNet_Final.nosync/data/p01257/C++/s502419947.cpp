#include<bits/stdc++.h>
using namespace std;
int n,m,a[10];
int dp[100001];

int main(){
  while(1){
    cin>>n>>m;
    if(n==0&&m==0)break;
    for(int i=0;i<n;i++)cin>>a[i];
    
    int L=1,R=m,M;
    while(L<R){
      M=(L+R)/2;
      memset(dp,-1,sizeof(dp));
      dp[0]=0;
      for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){          
          if(dp[j]==-1){
            if(j-a[i]>=0&&dp[j-a[i]]!=-1&&dp[j-a[i]]<M)
              dp[j]=dp[j-a[i]]+1;
          }else{
            dp[j]=0;
          }
        }
      }
      if(dp[m]==-1)L=M+1;
      else R=M;
    }
    cout<<L<<endl;    
  }
  return 0;
}