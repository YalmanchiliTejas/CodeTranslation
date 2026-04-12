// In the Name of Allah. Ya Ali!
#include<bits/stdc++.h>
#define bp __builtin_popcount
typedef long long ll;
const ll MAX_N = 1e4+10;
const ll MAX_K = 105;
const ll MOD = 1e9+7;
using namespace std;

ll dp[MAX_N][MAX_K];
int a[MAX_N];
int m,n;

int main()
{
    string k;
    cin >> k >> m;
    n = k.length();
    reverse(k.begin(),k.end());
    for(int i = 1;i<=n;++i)
        a[i] = (k[i-1]-'0');
    dp[0][0] = 1;
    for(int i = 1;i<=n;++i)
    {
        for(int j = 0;j<m;++j)
        {
            for(int t = 0;t<=9;++t)
            {
                dp[i][j] += dp[i-1][(j-(t%m)+m)%m];
                dp[i][j] %= MOD;
            }
        }
    }
    ll ans = 0;
    int now = 0;
    for(int i = n;i>=1;--i)
    {
        for(int j = 0;j<a[i];++j)
            ans += dp[i-1][(m-((now+j)%m))%m],ans %= MOD;
        now += a[i];
        now %= m;
    }
    if (!now)
        ans++;
    ans += MOD-1;
    ans %= MOD;
    cout << ans;
    return 0;
}
