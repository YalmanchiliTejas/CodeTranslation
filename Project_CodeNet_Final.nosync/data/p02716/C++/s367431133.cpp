#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int N = 2e5+5;

ll n , a[N] , dp[N][5];
bool vis[N][5];

ll solve(int i , int rem)
{
    if (i>n) return 0;

    if (vis[i][rem])
        return dp[i][rem];

    ll ans = a[i] + solve(i+2 , rem);
    if (rem) ans = max(ans , solve(i+1 , rem-1));

    vis[i][rem] = 1;
    return dp[i][rem] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    ll ans = -2e18 , del = 1 + n%2;

    for(int i=1; i<=del+1; i++)
    {
        ans = max(ans , solve(i , del-(i-1)));
    }

    cout << ans << "\n";


    return 0;
}