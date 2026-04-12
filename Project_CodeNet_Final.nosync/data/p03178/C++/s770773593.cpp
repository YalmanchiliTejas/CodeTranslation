#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[10005][2][100];
string s;
ll n,d;
ll solve(ll pos,ll tight,ll mo)
{
    if(pos==n)
    {
        return (mo==0);
    }
    if(dp[pos][tight][mo]!=-1)
    return dp[pos][tight][mo];
    ll ret=0;
        ll up=(tight?(s[pos]-'0'):9);
        //cout<<up<<" ";
        for(ll di=0;di<=up;di++)
        {
            ret=(ret%mod+solve(pos+1,(tight&(di==up)),(mo+di)%d)%mod)%mod;
        }
    return dp[pos][tight][mo]=ret;
}
int main()
{
    cin>>s>>d;
    memset(dp,-1,sizeof dp);
    n=s.length();
    ll ans=solve(0,1,0);
    ans=(ans%mod-1+mod)%mod;
    cout<<ans<<endl;
}
