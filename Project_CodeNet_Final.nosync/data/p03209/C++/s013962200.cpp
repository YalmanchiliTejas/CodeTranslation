#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
const ll MAX_L = 55;

ll buns[MAX_L];
ll paty[MAX_L];
ll total[MAX_L];

void init_burger()
{
    buns[0] = 0;
    paty[0] = 1;
    total[0] = 1;
    
    bool overflow = false;
    rep(i, 1, MAX_L)
    {
        paty[i] = (paty[i - 1] + 1) * 2  - 1;
        buns[i] = buns[i - 1] * 2  + 2;
        total[i] = paty[i] + buns[i];
    }
}

ll ans = 0;

void solve(ll n, ll x)
{
    // cout << n << ' ' << x << ' ' << ans << endl;
    if (x == 0) return;
    if (n == 0)
    {
        ++ans;
        return;
    }

    if (x >= total[n])
    {
        ans += paty[n];
    }
    else if (x >= 2 + total[n - 1])
    {
        ans += paty[n-1] + 1;
        solve(n-1, x - total[n-1] - 2);
    }
    else if (x == 1 + total[n - 1])
        ans += paty[n-1];
    else
    {
        solve(n-1, x-1);
    }
    return;
}

int main()
{
    init_burger();

    ll n, x;
    cin >> n >> x;

    solve(n, x);
    
    cout << ans << endl;
    return 0;
}