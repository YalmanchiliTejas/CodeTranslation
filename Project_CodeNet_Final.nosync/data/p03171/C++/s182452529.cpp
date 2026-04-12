#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
long long dp[N][N];
long long a[N];
long long play(int l,int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(l==r)        return dp[l][r] = a[l];
    return dp[l][r] = max(a[l]-play(l+1,r),a[r]-play(l,r-1));
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%lld",&a[i]);
    memset(dp,-1,sizeof dp);
    printf("%lld\n",play(1,n));
    return 0;
}
