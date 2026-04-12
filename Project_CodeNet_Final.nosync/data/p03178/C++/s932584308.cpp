/*input
98765432109876543210
58
*/

//sometimes it's the people who no one imagines anything of 
//who do the things that no one can imagine.

//code author: iamxlr8

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 300005
#define mod 1000000007
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll d;
string k;
vector<ll> num;
ll dp[10005][2][102];

ll fun(ll id,ll small,ll rem)
{
    if(id==num.size())
        return (rem==0);
    if(dp[id][small][rem]!=-1)
        return dp[id][small][rem];
    ll lmt=9;
    if(!small)
        lmt=num[id];
    ll ans=0;
    for(ll x=0;x<=lmt;x++)
    {
        ll nsmall=small;
        if(x<lmt)
            nsmall=1;
        ans=(ans%mod+fun(id+1,nsmall,(rem+x)%d)%mod)%mod;
    }
    return dp[id][small][rem]=ans;
}

ll solve(string x)
{
    for(ll i=0;i<x.size();i++)
        num.push_back(x[i]-'0');
    memset(dp,-1,sizeof(dp));
    ll ans=fun(0,0,0)-1;
    if(ans<0)
        ans+=mod;
    return ans;
}

int main() 
{
    off;
    cin>>k>>d;
    cout<<solve(k);
    return 0;
}