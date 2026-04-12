#include<bits/stdc++.h>
using namespace std;
long int dp[3001][3001];
int main(){
  int n;
  cin>>n;
  long long int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  memset(dp,0,sizeof dp);
  int i=0,j=0;
  while(i<n&&j<n){
      if(i==j){
      dp[i][j]=a[i];
      i++;j++;
      }
    }
    i=0;j=1;
    while(i<n&&j<n){
        if(j==i+1){
        dp[i][j]=max(a[i],a[j]);
        i++;
        j++;
        }
    }
    i=0;j=0;
    for(int k=2;k<n;k++){
        i=0;j=i+k;
        while(i<n&&j<n){
            if(j==i+k)
            dp[i][j]=max(a[j]+min(dp[i][j-2],dp[i+1][j-1]),a[i]+min(dp[i+1][j-1],dp[i+2][j]));
            i++;j++;
        }
    }
    cout<<dp[0][n-1]-min(dp[0][n-2],dp[1][n-1]);
}