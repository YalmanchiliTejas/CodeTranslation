#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define REP(i, start, end) for (ll i = start, i##Len = (end); i < i##Len; ++i)
#define REPR(i, start, end) for (ll i = start, i##Len = (end); i > i##Len; --i)
using ll = long long;
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> used(m, -1), dp(m);
    used[x] = n;
    dp[x] = x;
    n -= 1;
    bool flag = 1;
    ll ans = x;

    while (n > 0 && x)
    {
        x = x * x % m;
        ans += x;

        if (flag && used[x] != -1)
        {
            flag = 0;
            ll per = (used[x] - n);
            ll div = n / (used[x] - n);
            ll mod = n % (used[x] - n);
            if (per > n || div == 0)
                break;
            else if (mod == 0)
            {
                div -= 1;
                mod = per;
            }
            ans += (ans - dp[x]) * div;
            n = mod;
        }
        else
        {
            used[x] = n;
            dp[x] = ans;
        }
        --n;
    }

    cout << ans << endl;
}