#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int N = 1e5 + 10;
const int D = 1e2 + 1;

ll dp[N][D][2];

ll solve(int n, int curD, string &k, int d, bool lower)
{
    if(n == k.length())
        return curD == 0;

    ll &ans = dp[n][curD][lower];

    if(ans != -1)
        return ans;

    ans = 0;

    if(lower)
    {
        for(int i = 0; i < 10; i++)
            ans = (ans + solve(n + 1, (curD + i) % d, k, d, 1)) % mod;
    }
    else
    {
        int dig = k[n] - '0';
        ans = solve(n + 1, (curD + dig) % d, k, d, 0);

        for(int i = 0; i < dig; i++)
            ans = (ans + solve(n + 1, (curD + i) % d, k, d, 1)) % mod;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    string k;
    int d;
    cin >> k >> d;

    ll ans = (solve(0, 0, k, d, 0) - 1 + mod) % mod;

    cout << ans << endl;

    return 0;
}