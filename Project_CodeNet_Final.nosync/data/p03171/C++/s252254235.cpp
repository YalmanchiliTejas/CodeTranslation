#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
ll n,a[3005],dp[3005][3005][2];
int main(void){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int k=0;k<n;k++){
        for(int i=1;i+k<=n;i++){
            int l=i,r=i+k;
            dp[l][r][0]=max(dp[l+1][r][1]+a[l],dp[l][r-1][1]+a[r]);
            dp[l][r][1]=min(dp[l+1][r][0]-a[l],dp[l][r-1][0]-a[r]);
        }
    }
    printf("%lld\n",dp[1][n][0]);
}
