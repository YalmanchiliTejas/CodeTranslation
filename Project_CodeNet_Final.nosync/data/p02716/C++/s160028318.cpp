#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 2e5+9;
const long long inf = 1e15;

int n,a[N];
long long dp[N][3],ans=-inf;

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<3;j++) dp[i][j]=-inf;
    }
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i<=n/2;i++){
        dp[i][0] = dp[i-1][0] + a[(2*i)-1];
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]) + a[2*i];
        dp[i][2] = max(max(dp[i-1][2],dp[i-1][1]),dp[i-1][0]) + a[(2*i)+1];
    }
    if(n%2==0) ans=max(dp[n/2][0],dp[n/2][1]);
    else{
        for(int i = 0;i<3;i++){
            ans=max(ans,dp[n/2][i]);
        }
    }
    printf("%lld\n", ans);
}