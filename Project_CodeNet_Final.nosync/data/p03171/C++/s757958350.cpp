#include <bits/stdc++.h>
using namespace std;

typedef vector <long long> vi;
typedef vector <vi> vvi;
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define ll long long
#define MAXN 3005

ll in[MAXN];
ll dp[MAXN][MAXN][2];

ll fun(ll l, ll r, ll t)
{
    if (r < l)
        return 0;
    
    if (dp[l][r][t] == -1)
    {
        if (t == 1)
        {
            dp[l][r][t] = max(fun(l + 1, r, 0) + in[l], fun(l, r - 1, 0) + in[r]);
            //cout << l << " " << r << " " << t << "\n" << fun(l + 1, r, 0) + in[l] << "\n" << fun(l, r - 1, 0) + in[r] << "\n\n";
        }
        else
        {
            dp[l][r][t] = min(fun(l + 1, r, 1) - in[l], fun(l, r - 1, 1) - in[r]);
            //cout << l << " " << r << " " << t << "\n" << fun(l + 1, r, 1) - in[l] << "\n" << fun(l, r - 1, 1) - in[r] << "\n\n";
        }
    }
    return dp[l][r][t];
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> in[i];
    
    cout << fun(0, n - 1, 1) << "\n";
}
