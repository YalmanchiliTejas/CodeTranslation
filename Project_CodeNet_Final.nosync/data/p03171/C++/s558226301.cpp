#include <bits/stdc++.h>
#define ll long long int
#define N 3000
#define f(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << endl
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define all(x) x.begin(), x.end()
#define PI 3.14159265
#define cot cout.tie(0)
using namespace std;
/**
        * @author :: Sawlani
        *
        */

ll n;
ll a[N + 1];
ll dp[3001][3001][2];

ll rec(ll i, ll j, ll p)
{
    if (i == j)
        return p == 1 ? a[i] : -a[i];

    if (dp[i][j][p] != -1)
        return dp[i][j][p];

    ll c = rec(i + 1, j, p % 2 + 1);
    ll d = rec(i, j - 1, p % 2 + 1);
    ll ans;
    if (p == 1)
    {
        c = a[i] + c;
        d = a[j] + d;
        ans = (c > d ? c : d);
    }
    else
    {
        c = -a[i] + c;
        d = -a[j] + d;
        ans = (c < d ? c : d);
    }

    return dp[i][j][p] = ans;
}
int main()
{
   // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));
    cin >> n;

    f(i, 1, n) cin >> a[i];

    cout << rec(1, n, 1) << endl;
}