#include <bits/stdc++.h>
#define INF 1e9
#define REP(i, n, a) for (int i = a; i < n; i++)
#define rep(i, n) REP(i, n, 0)
using namespace std;
typedef long long ll;

ll num[60], numm[60];
ll solve(ll lev, ll pos)
{
    if (pos == 0)
        return 0;
    if (lev == 0)
        return 1;
    if (pos >= numm[lev - 1] + 2)
        return solve(lev - 1, pos - numm[lev - 1] - 2) + num[lev - 1] + 1;
    else
        return solve(lev - 1, pos - 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    num[0] = 1;
    numm[0] = 1;
    REP(i, n, 1)
    {
        num[i] = 2 * num[i - 1] + 1;
        numm[i] = 2 * numm[i - 1] + 3;
    }
    cout << solve(n, x) << endl;
}