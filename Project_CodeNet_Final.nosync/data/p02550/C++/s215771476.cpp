#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
typedef pair<int, int> P;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x, m;
    cin >> n >> x >> m;
    if(x==0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> flag(1000000, -1);
    flag[x] = 0;
    vector<ll> dp(1000000);
    dp[0] = x;
    ll l = 0, r = 0;
    rep(i, m)
    {
        dp[i + 1] = (dp[i] * dp[i]) % m;
        if (flag[dp[i + 1]] >= 0)
        {
            l = flag[dp[i + 1]];
            r = i + 1;
        }
        flag[dp[i + 1]] = i + 1;
    }
    vector<ll> sum = dp;

    rep(i, m)
    {
        sum[i + 1] += sum[i];
    }

    if (n < l)
    {
        cout << sum[n - 1] << endl;
    }
    else
    {
        ll ans = 0;
        if (l > 0)
        {
            ans += sum[l - 1];
            n -= l;
        }
        ans += (sum[r] - sum[l]) * (n / (r - l));
        if (l > 0)
        {
            ans += sum[l + n % (r - l) - 1] - sum[l - 1];
        }
        else
        {
            ans += sum[l + n % (r - l) - 1];
        }
        cout << ans << endl;
    }
}