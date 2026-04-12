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

string s;
ll n;
ll dp[101][3][4];
ll rec(ll i, ll tight, ll k)
{

    if (i == n && k==0)
        return 1;
    else if(i==n)
    return 0;

    if(dp[i][tight][k]!=-1)
    return dp[i][tight][k];
     

    ll no = (int)s[i] - 48;
    ll ans = 0;

    if (i == 0)
    {
        ans += rec(i + 1, tight, k);

        if (k > 0)
        {
            f(j, 1, no - 1)
                ans += rec(i + 1, tight, k - 1);

            ans +=rec(i + 1, 1, k - 1);
        }
    }
    else
    {
        if (!tight)
        {
            ans +=rec(i + 1, 0, k);
            if (k > 0)
            {
                f(j, 1, 9)
                {
                    ans +=rec(i + 1, tight, k - 1);
                }
            }
        }
        else
        {
            if (no != 0)
                ans +=rec(i + 1, 0, k);
            else if (no == 0)
                ans +=rec(i + 1, 1, k);

            if (k > 0)
            {
                f(j, 1, no - 1)
                {
                    ans +=  rec(i + 1, 0, k - 1);
                }
                if (no != 0)
                    ans +=  rec(i + 1, tight, k - 1);
            }
        }
    }

    return dp[i][tight][k]=ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    memset(dp,-1,sizeof(dp));

    cin >> s;
    ll k;
    cin >> k;

    n = s.length();
     cout << rec(0, 0, k);
}