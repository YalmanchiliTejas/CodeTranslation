#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define print(x) cout << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll dp[3005][3005], a[3005], n;

ll rec(ll l, ll r)
{
    if (r < l)
        return 0;
    if (dp[l][r] != 1e18)
        return dp[l][r];
    ll t, k = 0;
    if (((r - l) & 1) == (n & 1))
        t = 0;
    else
        t = 1;
    if (t == 0)
    {
        dp[l][r] = 1e18;
        dp[l][r] = min(dp[l][r], min(-1 * a[l] + rec(l + 1, r), -1 * a[r] + rec(l, r - 1)));
    }
    else
    {
        dp[l][r] = -1e18;
        dp[l][r] = max(dp[l][r], max(a[l] + rec(l + 1, r), a[r] + rec(l, r - 1)));
    }
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    f(1, 3005) fi(1, 3005) dp[i][j] = 1e18;
    cin >> n;
    f(1, n + 1) cin >> a[i];
    ll ans = rec(1, n);
    cout << ans;

    return 0;
}