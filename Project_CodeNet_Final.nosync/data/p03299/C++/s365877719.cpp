#include<bits/stdc++.h>
#define maxn 110
#define ll long long
using namespace std;
const int mod=1e9+7;
int h[maxn],a[maxn],b[maxn],sz,n;

ll qpow(ll a,ll x)
{
    ll ret=1;
    while(x>0)
    {
        if(x&1) ret=ret*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return ret;
}
ll cal(int lb,int ub)
{
    ll ret=qpow(2,ub+1)+mod-qpow(2,lb);
    if(ret>=mod)ret-=mod;
    return ret;
}
ll dp[maxn][maxn];
void upd(int &x,int y)
{
    x=(x+y>=mod?x+y-mod:x+y);
}
int main()
{
    scanf("%d",&n);
    h[sz++]=1;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        h[sz++]=a[i];
    }
    sort(h,h+sz); sz=unique(h,h+sz)-h;
    dp[0][0]=2;
    for(int i=0;i<n;++i) b[i]=lower_bound(h,h+sz,a[i])-h;
    for(int i=1;i<=b[0];++i)
    {
        int ub=a[0]-(h[i-1]+1)+1;
        int lb=a[0]-(h[i])+1;
        //printf("h[%d]=%d,lb=%d,ub=%d\n",i,h[i],lb,ub);
        dp[0][i]=cal(lb,ub);
    }

    for(int i=1;i<n;++i)
    {
        dp[i][0]=dp[i-1][0]*2%mod;
        ll t=qpow(2,max(0,a[i]-a[i-1]));
        for(int j=1;j<=b[i];++j)
            if(dp[i-1][j])
                dp[i][j]=(dp[i][j]+dp[i-1][j]*t)%mod;
        for(int j=b[i]+1;j<sz;++j)
            if(dp[i-1][j])
            dp[i][0]=(dp[i][0]+dp[i-1][j]*2)%mod;
        if(b[i]>b[i-1])
        {
            for(int j=b[i-1]+1;j<=b[i];++j)
            {
                int ub=a[i]-(h[j-1]+1)+1;
                int lb=a[i]-(h[j])+1;
                ll ret=cal(lb,ub);
                dp[i][j]=(dp[i][j]+dp[i-1][0]*ret)%mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<sz;++i)
    {
        ans+=dp[n-1][i];
        if(ans>=mod) ans-=mod;
    }
    printf("%d\n",ans);
        //for(int j=len+1;j<sz;++j)
    return 0;
}
