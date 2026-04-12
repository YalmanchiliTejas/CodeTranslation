// In the name of Allah. Ya ali!
#include<bits/stdc++.h>
#define double long double
#define debug(x)//  cerr << #x << " = " << x << endl
typedef long long ll;
const ll MAX_N = 2e5+100;
const ll MOD = 1e9+7;
using namespace std;

ll dp[MAX_N];
ll sum[MAX_N];
int n,m;

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
    int mn = 1e9;
    if (vc[0]%2==0)
        mn = vc[0]+1;
    for(auto x:vc)
    {
        if (x&1)
            mn = min(mn,x);
    }
    int lim = mn;
    dp[1] = 1;
    dp[3] = 1;
    for(int i = 5;i<=n;i+=2)
    {
        dp[i] = (dp[i-2]*2ll)%MOD;
        if (i>=lim+3)
            dp[i] = (dp[i]-dp[i-lim-3]+MOD+MOD)%MOD;
    }
    ll ans = 0;
    for(ll i = 1;i<=min(n-1,lim);i+=2)
    {
        ans += ((i+1ll)*dp[n-i])%MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
