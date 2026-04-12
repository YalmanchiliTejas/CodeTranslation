#include <bits/stdc++.h>
#define ll long long int
#define N 10000
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

string k;
ll d;
ll n;
ll dp[N + 1][2][101];
const ll M = 1e9 + 7;

ll rec(ll i, ll tight, ll sum)
{
    if (i == n && sum == 0)
        return 1;
    else if (i == n)
        return 0;

    if (dp[i][tight][sum] != -1)
        return dp[i][tight][sum];
    int no = (int)k[i] - 48;

    //debug(no);
    ll ans = 0;

    if (i == 0)
    {
        f(j, 0, no - 1)
            ans = (ans + rec(i + 1, tight, (sum + j) % d)) % M;

        ans = (ans + rec(i + 1, tight + 1, (sum + no) % d)) % M;
    }
    else
    {
        if (tight)
        {
            f(j, 0, no - 1)
            {
                ans = (ans + rec(i + 1, tight - 1, (sum + j) % d)) % M;
            }
            ans = (ans + rec(i + 1, tight, (sum + no) % d)) % M;
        }
        else
        {
            f(j, 0, 9)
            {
                ans = (ans + rec(i + 1, tight, (sum + j) % d)) % M;
            }
        }
    }
    return dp[i][tight][sum] = ans;
}
int main()
{
     cin >> k >> d;

    memset(dp, -1, sizeof(dp));

    n = k.length();
    cout << (rec(0, 0, 0) % M - 1 % M + M) % M;
}