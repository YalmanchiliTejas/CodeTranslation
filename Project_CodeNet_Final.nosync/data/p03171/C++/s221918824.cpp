#include<bits/stdc++.h>
#define ll long long
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;
using namespace std;
int n;
ll a[3005];
pair<ll,ll>memo[3005][3005][2];
pair<ll,ll> dp(int l,int r,int i,int d,int side,int m)
{
    if(l>r)
    {
        return {0,0};
    }
    if(memo[i][d][side].first!=-1)
    {
        return memo[i][d][side];
    }
    pair<ll,ll>ret1,ret2;
    ret1=dp(l+1,r,l+1,d+1,0,m^1);
    ret2=dp(l,r-1,r-1,d+1,1,m^1);
    if(!m)
    {
        ret1.first+=a[l];
        ret2.first+=a[r];
        pair<ll,ll>p;
        p.first=max(ret1.first,ret2.first);
        p.second=min(ret1.second,ret2.second);
        return memo[i][d][side]=p;
    }
    else
    {
        ret1.second+=a[l];
        ret2.second+=a[r];
        pair<ll,ll>p;
        p.second=max(ret1.second,ret2.second);
        p.first=min(ret1.first,ret2.first);
        return memo[i][d][side]=p;
    }
}
int main()
{
    scanf("%d",&n);
    ll sum=0;
    for(int i=0;i<n;++i)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    memset(memo,-1,sizeof memo);
    //watch(sum)
    ll F=dp(0,n-1,0,0,0,0).first;
    //watch(F)
    printf("%lld",F-(sum-F));
    return 0;
}


