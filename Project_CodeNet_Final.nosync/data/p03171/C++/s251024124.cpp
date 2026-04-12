#include<bits/stdc++.h>
using namespace std;
int main(){
int  N;
  cin>>N;
  vector<int64_t>a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  int64_t dp[N][N];
  for(int i=0;i<N;i++)
    dp[i][i]=a.at(i);
  for(int i=0;i<N-1;i++)
    dp[i][i+1]=max(a.at(i),a.at(i+1))-min(a.at(i),a.at(i+1));
  for(int l=2;l<=N-1;l++){
    for(int i=0;i<N-l;i++){
    int j=i+l;
    dp[i][j]=
 max(a[i]+min(dp[i+2][j]-a[i+1],dp[i+1][j-1]-a[j]),a[j]+min(dp[i+1][j-1]-a[i],dp[i][j-2]-a[j-1]));
    
    
    }
  
  }cout<<dp[0][N-1]<<endl;
   return 0;
}