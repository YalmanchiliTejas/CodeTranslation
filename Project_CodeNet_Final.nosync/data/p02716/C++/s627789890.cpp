#include <bits/stdc++.h>
using namespace std;

long long dp[200001][3];
long long arr[200000];
int n;
const long long INF=1e16;

long long ans(int ind,int left) {
    if (left<0) {
        return -INF;
    }
    if (ind>=n) {
        return 0;
    }
    if (dp[ind][left]!=-1) {
        return dp[ind][left];
    }
    dp[ind][left]=arr[ind]+max({ans(ind+2,left),ans(ind+3,left-1),ans(ind+4,left-2)});
    return dp[ind][left];
}

int main(void) {
    memset(dp,-1,sizeof(dp));
    scanf("%d\n",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }
    if (n%2==0) {
        printf("%lld",max(ans(0,1),ans(1,0)));
    }
    else {
        printf("%lld",max({ans(0,2),ans(1,1),ans(2,0)}));
    }
}