#include<bits/stdc++.h>
using namespace std;
long long int dp[3010][3010];
long long int a[3001];
int n;

/*long long int solve(int i, int j){
      if(dp[i][j]!=-1)return dp[i][j];
      
      if(i==j)return dp[i][j]=a[i];
      if(i>j)return dp[i][j]=0;
      
      dp[i][j]=max(a[i]-solve(i+1, j), a[j]-solve(i, j-1));
      //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
      return dp[i][j];
}*/

int main(){
      cin>>n;
      memset(dp, 0, sizeof(dp));
      for(int i=0; i<n; i++)
            cin>>a[i];
      //cout<<solve(0, n-1)<<'\n';
      for(int l=0; l<n; l++){
            for(int i=0; i<n; i++){
                  int j=i+l;
                  if(i==j)dp[i][j]=a[j];
                  else {
                        dp[i][j]=max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
                  }
            }
      }
      cout<<dp[0][n-1];
}