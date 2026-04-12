#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define LL long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define sch(n) scanf(" %c", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define fr first
#define sc second
#define all(a)  a.begin(),a.end()
#define Unique(a)  sort(all(a)),a.erase(unique(all(a)),a.end())

#define inf (1LL<<50)
#define eps 1e-9

ll Set(ll n, ll pos)
{
    return n|(1LL<<pos);
}

bool Check(ll n, ll pos)
{
    return (bool) (n&(1LL<<pos));
}

ll a[3050];
ll dp[3050][3050][2];

ll solve(ll b, ll e, bool p)
{
    if (b == e)
        return (p==0?a[b]:-a[b]);

    ll &ret = dp[b][e][p];
    if (ret != -1)
        return ret;

    if (p == 0)
    {
        ret = max(solve(b+1, e, 1) + a[b], solve(b, e-1, 1) + a[e]);
    }
    else
    {
        ret = min(solve(b+1, e, 0) - a[b], solve(b, e-1, 0) - a[e]);
    }

 //   cout << p << " " << b << " " << e << " " << ret << endl;

    return ret;
}

int main ()
{
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, ts, i, j, k, x, y, z, q, m, n, cap;

    while(sl(n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            sl(a[i]);
            a[i] *= 2;
        }

        memset(dp, -1, sizeof(dp));

        printf("%lld\n", solve(1, n, 0)/2);
    }
    return 0;
}
