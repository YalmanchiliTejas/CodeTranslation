#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define inf 1e18
using namespace std;
int dp[3001][3001];

int solve(int *a,int i,int j){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=inf){
        return dp[i][j];
    }
    if(i==j){
        return dp[i][j]=a[i];
    }
    if(i==j+1){
        return dp[i][j]=max(a[i],a[j]);
    }
    int op1=a[i]+min(solve(a,i+2,j),solve(a,i+1,j-1));
    int op2=a[j]+min(solve(a,i,j-2),solve(a,i+1,j-1));
    return dp[i][j]=max(op1,op2);
}
int32_t main(){
    int n;
    cin>>n;
    int a[n+1];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=inf;
        }
    }    
  
    int x=solve(a,1,n);
    int y=sum-x;
    int ans=x-y;
    cout<<ans<<endl;
    return 0;
}