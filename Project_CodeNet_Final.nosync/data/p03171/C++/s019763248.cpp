#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long dp[n+5][n+5]={};
    for(int i=n-1;i>=0;i--)for(int j=i;j<n;j++){
        if(i==j) dp[i][j]=a[i];
        else{
            dp[i][j]=max(dp[i][j],max(a[i]+min(dp[i+1][j-1],dp[i+2][j]),a[j]+min(dp[i+1][j-1],dp[i][j-2])));
        }
    }
    long long ans=dp[0][n-1];
    if(ans==a[0]+dp[2][n-1]) ans-=dp[1][n-1];
    else if(ans==a[0]+dp[1][n-2]) ans-=dp[1][n-1];
    else if(ans==a[n-1]+dp[1][n-2] || ans==a[n-1]+dp[0][n-3]) ans-=dp[0][n-2];
    cout<<ans<<endl;
}