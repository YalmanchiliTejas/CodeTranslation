#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll mod=1e9+7,d,dp[10005][2][2][105],len;
char str[10005];

ll func(ll indx, ll isSmall, ll isStart, ll rem)
{
    if(indx==len) return (!rem);
    if(dp[indx][isSmall][isStart][rem]!=-1) return dp[indx][isSmall][isStart][rem];
    ll val=str[indx]-'0',ans=0;
    ll rng=isSmall? 9 : val;
    if(isStart)
    {
        for(ll i=1; i<=rng; i++)
        {
            ans+=func(indx+1, isSmall | i<(str[indx]-'0'), 0, (rem+i)%d);
            ans%=mod;
        }
        if(indx+1<len) ans+=func(indx+1, 1, 1, 0);
        ans%=mod;
    }
    else
    {
        for(ll i=0; i<=rng; i++)
        {
            ans+=func(indx+1, isSmall | i<(str[indx]-'0'), 0, (rem+i)%d);
            ans%=mod;
        }
    }

    return dp[indx][isSmall][isStart][rem]=ans;
}


int main()
{
    ll i,j;
    scanf("%s",str);
    scanf("%lld",&d);
    len=strlen(str);
    memset(dp, -1, sizeof dp);
    ll ans=func(0,0,1,0);
    printf("%lld\n",ans);
    return 0;

}
