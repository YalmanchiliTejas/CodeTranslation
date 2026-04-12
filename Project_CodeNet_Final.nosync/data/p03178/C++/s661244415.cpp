#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ind(a) scanf("%d", &a)
#define inlld(a) scanf("%lld", &a)
#define ind2(a, b) scanf("%d%d", &a, &b)
#define inlld2(a, b) scanf("%lld%lld", &a, &b)
#define ind3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define inlld3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

using namespace std;

const int N=1e4+5;
const int MOD=1e9+7;

typedef long long ll;
typedef long double ld;

ll d, dp[N][100][2][2];
string s;
vector<ll>digs;

ll solve(ll i, ll mod, ll islesser, ll hasstarted)
{
    if(i==digs.size())
        return (mod==0 && hasstarted==1);
    if(dp[i][mod][islesser][hasstarted]!=-1)
        return dp[i][mod][islesser][hasstarted];
    if(islesser && hasstarted)
    {
        ll ret=0;
        for(ll a=0; a<=9; a++)
            ret=(ret+solve(i+1, (mod+a)%d, islesser, hasstarted))%MOD;
        // printf("%lld %lld %lld %lld %lld\n", i, mod, islesser, hasstarted, ret);
        return dp[i][mod][islesser][hasstarted]=ret;
    }
    if(islesser)
    {
        ll ret=0;
        ret+=solve(i+1, 0, 1, 0);
        for(ll a=1; a<=9; a++)
            ret=(ret+solve(i+1, (mod+a)%d, 1, 1))%MOD;
        // printf("%lld %lld %lld %lld %lld\n", i, mod, islesser, hasstarted, ret);
        return dp[i][mod][islesser][hasstarted]=ret;
    }
    ll ret=0;
    ret=solve(i+1, (mod+digs[i])%d, 0, 1);
    for(ll a=0; a<digs[i]; a++)
        ret=(ret+solve(i+1, (mod+a)%d, 1, 1))%MOD;
    // printf("%lld %lld %lld %lld %lld\n", i, mod, islesser, hasstarted, ret);
    return dp[i][mod][islesser][hasstarted]=ret;
}

int main() 
{
    cin>>s;
    cin>>d;
    ll x=s.length();
    for(ll a=0; a<x; a++)
        digs.pb((s[a]-'0'+0));
    memset(dp, -1, sizeof(dp));
    ll ans=0;
    ans=solve(1, 0, 1, 0);
    ans=(ans+solve(1, digs[0]%d, 0, 1))%MOD;
    for(ll a=1; a<digs[0]; a++)
        ans=(ans+solve(1, a%d, 1, 1))%MOD;
    printf("%lld\n", ans);
    return 0;
}

