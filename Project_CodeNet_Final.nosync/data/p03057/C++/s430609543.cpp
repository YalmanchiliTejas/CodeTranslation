// In the name of Allah. Ya ali!
#include<bits/stdc++.h>
#define double long double
typedef long long ll;
const ll MAX_N = 2e5+10;
const ll MOD = 1e9+7;
using namespace std;

ll dp[MAX_N];
ll sum[MAX_N];
int n,m;

ll solve(ll lim)
{
    if (n&1)
        return 0;
    dp[1] = 1;
    dp[3] = 1;
    sum[1] = 1;
    sum[3] = 2;
    for(int i = 5;i<=n+1;i+=2)
    {
        dp[i] = sum[i-2];
        if (i-2>lim)
            dp[i] = (dp[i]-sum[i-lim-3]+MOD)%MOD;
        sum[i] = (sum[i-2]+dp[i])%MOD;
    }
    ll ans = 0;
    ans = dp[n+1];
    for(ll i = 1;i<=lim;i+=2)
    {
        ans += (i*dp[n-i])%MOD;
        ans %= MOD;
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    string s;
    cin >> s;
    if (s[0]=='B')
    {
        for(int i = 0;i<m;++i)
        {
            if (s[i]=='B')
                s[i] = 'R';
            else
                s[i] = 'B';
        }
    }
    bool ok = false;
    for(int i = 0;i<m;++i)
        ok |= (s[i]=='B');
    if (!ok)
    {
        dp[1] = 1;
        dp[3] = 1;
        sum[1] = 1;
        sum[2] = 1;
        sum[3] = 2;
        for(int i = 4;i<=n+1;++i)
        {
            dp[i] = sum[i-2];
            sum[i] = (sum[i-1]+dp[i])%MOD;
        }
        ll ans = dp[n+1]+1;
        for(ll i = 1;i<n;++i)
        {
            ans += (i*dp[n-i])%MOD;
            ans %= MOD;
        }
        cout << ans;
        return 0;
    }
    for(int i = m-1;i>=0;--i)
    {
        if (s[i]=='B')
        {
            m = i+1;
            break;
        }
    }
    vector<int> vc;
    int cnt = 0;
    for(int i = 0;i<m;++i)
    {
        if (s[i]=='B')
        {
            if (cnt)
                vc.push_back(cnt);
            cnt = 0;
        }
        else
            cnt++;
    }
    ok = false;
    for(auto x:vc)
        ok |= (x&1);
    if (!ok)
        return cout << solve(vc[0]+1),0;
    int mn = 1e9;
    if (vc[0]%2==0)
        mn = vc[0]+1;
    for(auto x:vc)
    {
        if (x&1)
            mn = min(mn,x);
    }
    cout << solve(mn);
    return 0;
}
