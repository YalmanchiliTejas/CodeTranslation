#include<bits/stdc++.h>
using namespace std;
int main(){int i,j,n;
cin>>n;
long long int dp[n+1][2];
long long a[n+1],k=-1000000009,l=n/2,ans;
ans=k;
memset(dp,k,sizeof(dp));
for(i=1;i<=n;i++)cin>>a[i];
if(n==1){cout<<a[1];return 0;}
if(n==2){cout<<max(a[1],a[2]);return 0;}
if(n==3){cout<<max(a[1],max(a[2],a[3]));return 0;}
dp[1][1]=a[1];
dp[2][1]=a[2];
dp[3][1]=a[1]+a[3];
dp[3][0]=a[3];
dp[4][0]=a[4];
dp[4][1]=a[4]+max(a[1],a[2]);
for(i=5;i<=n;i++){
    k=(i+1)/2;
    if(i%2){dp[i][1]=a[i]+dp[i-2][1];}
    else{dp[i][1]=a[i]+max(dp[i-2][1],dp[i-3][1]);}
    if(i%2){
        dp[i][0]=a[i]+max(dp[i-2][0],max(dp[i-3][1],dp[i-4][1]));
    }else{
        dp[i][0]=a[i]+max(max(dp[i-2][0],dp[i-3][0]),max(dp[i-4][1],dp[i-5][1]));
    }
}
if(n%2==0){ans=max(dp[n][1],dp[n-1][1]);}
else{
    ans=max(dp[n-1][1],dp[n-2][1]);
    ans=max(ans,dp[n][0]);
}
cout<<ans;
    return 0;}