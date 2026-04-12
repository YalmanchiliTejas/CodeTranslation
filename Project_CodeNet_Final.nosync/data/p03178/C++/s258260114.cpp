#include<bits/stdc++.h>
using namespace std;

#define ll long long
const long long MOD=1e9+7;
const long long MAXN=1e4+5;
const int MAXD=1e2+5;
ll n,d;
string k;
vector <long long> v;
ll dp[MAXN][2][MAXD];
ll solve(ll p,ll flag,ll res)
{
    if(p==(n))
    return (res==0);
    if(dp[p][flag][res]!=-1)
    return dp[p][flag][res];
    ll tot=0;
    int range=flag?v[p]:9;
    for(int i=0;i<=range;i++)
    {
        tot+=solve(p+1,flag && (i==range), (res+i)%d);
    }
    return dp[p][flag][res]=tot%MOD;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>k;
    n=k.size();
    cin>>d;
    for(int i=0;i<n;i++)
    {
        v.push_back(k[i]-'0');
    }
    ll ans=solve(0,1,0) %MOD;
    ans=ans-1;
    if(ans<0)
    ans+=MOD;
    cout<<ans<<"\n";
}