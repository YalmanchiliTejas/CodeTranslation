#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N];
ll sum[N],dp[N][3];
void setdp(int x,int y,ll v)
{
    if(y==x/2) dp[x][1]=max(dp[x][1],v);
    else if(y==x/2-1) dp[x][0]=max(dp[x][0],v);
    else if(y==x/2+1) dp[x][2]=max(dp[x][2],v);
}
ll getdp(int x,int y)
{
    if(y==x/2) return dp[x][1];
    else if(y==x/2-1) return dp[x][0];
    else if(y==x/2+1) return dp[x][2];
    return -inf;
}
int main()
{
    memset(dp,-inf,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=-inf;
    setdp(0,0,0);
    setdp(1,1,a[1]);
    setdp(1,0,0);
    for(int i=2;i<=n;i++)
        for(int j=i/2-1;j<=i/2+1;j++)
        setdp(i,j,getdp(i-2,j-1)+a[i]),setdp(i,j,getdp(i-1,j));
    printf("%lld\n",getdp(n,n/2));
}
