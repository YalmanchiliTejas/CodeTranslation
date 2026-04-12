#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll a,b,k;
vector <ll> num;
ll dp[10005][105][2];
string s;
ll calc(ll pos,ll remain,ll t)
{
    if(pos==num.size())
    {
        if(remain==0)
            return 1;
        return 0;
    }
    if(dp[pos][remain][t]!=-1&&t!=0)
        return dp[pos][remain][t];
    ll res=0,lm;
    if(t==0)
        lm=num[pos];
    else lm=9;
    for(ll i=0;i<=lm;i++)
    {
        ll nt=t;
        if(i<lm)
            nt=1;
        res=(res+calc(pos+1,(remain+i)%k,nt))%mod;
    }
    if(t==1)
        dp[pos][remain][t]=res;
    return res;
}
ll solve()
{
    for(ll i=0;i<s.size();i++)
        num.push_back(s[i]-48);
    memset(dp,-1,sizeof(dp));
    ll ans=calc(0,0,0);
    return (ans+mod)%mod;
}
 main()
{
      cin>>s;
      cin>>k;
      cout<<(solve()-1+mod)%mod;
}
