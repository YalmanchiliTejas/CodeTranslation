#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxn=2e5+10;
const LL inf=-1e18;
LL a[maxn];
int n;
LL dp[maxn][5];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=4;j++){
            dp[i][j]=inf;
        }
    }
    for(int i=1;i<=3;i++){
        dp[i][i-1]=a[i];
    }
    dp[3][0]=a[1]+a[3];
    for(int i=4;i<=n;i++){
        dp[i][0]=max(dp[i-2][0]+a[i],dp[i][0]);
        dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i]);
        dp[i][2]=max(dp[i-2][2],dp[i-3][1])+a[i];
        if(i>4){
            dp[i][2]=max(dp[i][2],dp[i-4][0]+a[i]);
        }
    }
    LL res=0;
    if(n&1){
        res=max(dp[n][2],max(dp[n-1][1],dp[n-2][0]));
    }
    else{
        res=max(dp[n][1],dp[n-1][0]);
    }
    printf("%lld\n",res);
    return 0;
}
