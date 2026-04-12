#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3010;
int a[M],n;
ll dp[2][M][M],sum;
ll dfs(int u,int l,int r,ll s)
{
    ll &re=dp[u][l][r];
    if(re)
        return re;
    if(l==r)
        return re=a[l];
    ll tmp[2]={dfs(!u,l+1,r,s-a[l]),dfs(!u,l,r-1,s-a[r])};
    if(tmp[0]<tmp[1]) re=s-tmp[0];
    else re=s-tmp[1];
    //printf("%d %d %d %lld\n",u,l,r,re);
    return re;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    printf("%lld\n",dfs(0,1,n,sum)-(sum-dfs(0,1,n,sum)));
    return 0;
}
