#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+69,INF=1e17;
int n;
int a[MAXN];
int dp[MAXN][3];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)for(int j=0;j<3;j++)dp[i][j]=-INF;
    dp[1][0]=a[1];
    for(int i=3;i<=n;i+=2)dp[i][0]=dp[i-2][0]+a[i];
    dp[2][1]=a[2];
    for(int i=4;i<=n;i+=2)dp[i][1]=max(dp[i-3][0],dp[i-2][1])+a[i];
    for(int i=3;i<=n;i++){
        dp[i][2]=dp[i-2][2]+a[i];
        dp[i][2]=max(dp[i][2],dp[i-3][1]+a[i]);
        if(i>=4)dp[i][2]=max(dp[i][2],dp[i-4][0]+a[i]);
    }
    int p=n&1;
    cout<<max(dp[n-1][p],dp[n][p+1]);
}