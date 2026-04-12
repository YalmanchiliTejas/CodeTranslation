#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
const int MAX_L = 55;

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

int main()
{
    init_burger();
    ll n, x;
    cin >> n >> x;

    int level_left = n;
    int level_now = n;
    ll ans = 0;

    while (x > 0)
    {
        ll num = total[level_now] + level_left - level_now;
        // cout << level_left << ' ' << level_now <<' ' << x << ' ' << num << ' ' << ans<< endl;

        if (num <= x)
        {
            x -= num;
            ans += paty[level_now];
            level_left = level_now;

            if (x > 0)
                --x, ++ans;
        }
        else
            --level_now;

        if (level_now < 0) break;
    }
    cout << ans << endl;
    return 0;
}