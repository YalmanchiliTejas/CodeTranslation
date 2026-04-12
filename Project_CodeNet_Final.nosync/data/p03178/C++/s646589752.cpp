#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string K;
ll n;
ll D;
ll dp[10004][102][2];
ll solve(ll pos,ll d,int tight)
{
    if(dp[pos][d][tight]!=-1)
    return dp[pos][d][tight];
    ll up = (tight)?K[pos]-'0':9;
    if(pos==n-1)
    {
        ll ans=0;
        for(int x=0;x<=up;x++)
        {
            if(x%D==d)
            ans++;
        }
        return ans;
    }
    ll ans=0;
    for(int x=0;x<=up;x++)
    {
        ans = (ans%mod+solve(pos+1,(D+d-x%D)%D,(tight&&(x==up))?1:0)%mod)%mod;
    }
    return dp[pos][d][tight]=ans;
}
int main() {
    cin>>K;
    cin.ignore();
    cin>>D;
    n = K.length();
    memset(dp,-1,sizeof dp);
    cout<<(mod+solve(0,0,1)-1)%mod;
}
