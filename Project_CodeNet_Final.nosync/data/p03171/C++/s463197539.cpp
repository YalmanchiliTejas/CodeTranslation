#include <bits/stdc++.h>
#define lli long long int
using namespace std;
#define MOD 1000000007
#define mod 1000000037
#define mod1 998244353
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define INF 2e9

vector<vector<lli> >dp;
vector<lli>v;

lli func(lli l,lli r)
{
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(l==r)
    {
        dp[l][r]=v[l];
        return v[l];
    }
    if(r==l+1)
    {
        dp[l][r]=max(v[l],v[r]);
        return dp[l][r];
    }
    //cout << l << " " << r << endl;
    lli a=func(l+2,r),b=func(l+1,r-1),c=func(l+1,r-1),d=func(l,r-2);
    //cout << a << " " << b << " " << c << " " << d << endl;
    dp[l][r]=max(min(v[l]+a,v[l]+b),min(v[r]+c,v[r]+d));
    return dp[l][r];
}

int main()
{
    fastio;
    lli n;
    cin >> n;
    v.resize(n);
    lli sum=0;
    for(lli i=0;i<n;i++)
    {
        cin >> v[i];
        sum+=v[i];
    }
    dp.resize(n);
    for(lli i=0;i<n;i++)
    {
        vector<lli>t(n,-1);
        dp[i]=t;
    }
    // cout << func(0,n-1) << endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<dp[i].size();j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    lli ans=2*func(0,n-1)-sum;
    cout << ans << endl;
}