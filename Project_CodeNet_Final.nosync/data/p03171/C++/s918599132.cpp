#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int a[n+1];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int dp[n+1][n+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        dp[i][i]=a[i];
    }
    
    for(int d=0;d<=n-1;d++){
        for(int i=1,j=d+1;i<=n-d && j<=n;i++,j++){
            if(i==j){
                continue;
            }
            int op1=a[i]+min(dp[i+2][j],dp[i+1][j-1]);
            int op2=a[j]+min(dp[i][j-2],dp[i+1][j-1]);
            dp[i][j]=max(op1,op2);
        }
    }    
    int x=dp[1][n];
    int y=sum-x;
    int ans=x-y;
    cout<<ans<<endl;
    return 0;
}