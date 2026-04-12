#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=3e3+5;
typedef long long ll;
ll dp[N][N][2];
int a[N];
void dfs(int,int);
int main(){
    memset(dp,0x3f,sizeof(dp));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    dfs(1,n);
    cout<<dp[1][n][0];
}
void dfs(int l,int r){
    if(dp[l][r][0]!=0x3f3f3f3f3f3f3f3f) return;
    if(l==r){
        dp[l][r][0]=a[l];
        dp[l][r][1]=-a[l];
        return;
    }
    dfs(l+1,r),dfs(l,r-1);
    dp[l][r][0]=max(dp[l+1][r][1]+a[l],dp[l][r-1][1]+a[r]);
    dp[l][r][1]=min(dp[l+1][r][0]-a[l],dp[l][r-1][0]-a[r]);
}
