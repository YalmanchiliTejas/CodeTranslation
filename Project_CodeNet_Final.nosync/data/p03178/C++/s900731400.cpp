#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define ll long long int
#define pii pair <ll , ll >
#define pb push_back
ll x8[] = {1, 1, 1, 0, 0, -1, -1, -1};
ll y8[] = {1, 0, -1, 1, -1, -1, 0, -1};
ll x4[] = {1, -1, 0, 0};
ll y4[] = {0, 0, 1, -1};
ll mod = 1e9 + 7;
ll inf = 1e18;
string k;
int d;
int len;
ll dp[10001][2][101];
ll solve(int pos, int isSmall, int curr)
{
    if(pos == len)
    {
        if(curr % d == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(dp[pos][isSmall][curr % d] != -1)
    {
        return dp[pos][isSmall][curr % d] % mod;
    }
    else
    {
        int limit = 9;
        if(!isSmall)
        {
            limit = k[pos] - '0';
        }
        ll ans = 0;
        for(int i = 0; i <= limit; i++)
        {
            if(i < k[pos] - '0')
            {
                ans += solve(pos + 1, 1, (curr + i) % d) % mod;
                ans %= mod;
            }
            else
            {
                ans += solve(pos + 1, isSmall, (curr + i) % d) % mod;
                ans %= mod;
            }
        }
        dp[pos][isSmall][curr] = ans % mod;
        return dp[pos][isSmall][curr];
    }
}
void getac()
{
    string t;
    cin >> t;
    k = t;

    cin >> d;
    len = k.length();
    for(int i = 0; i <= len; i++)
    {
        for(int j = 0; j <= d; j++)
        {
            dp[i][0][j] = -1;
            dp[i][1][j] = -1;
        }
    }
    ll ans = solve(0, 0, 0) % mod;
    ans = (ans - 1 + mod) % mod;
    cout << ans;
}
int  main()
{
    fastio;
    ll t;
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // freopen("_error.txt", "w", stderr);
    // #endif

    t = 1;


    while(t--)
    {
        getac();
    }

    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}