#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for (int i=a; i<b; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector <ll> a(n);
    loop(i,0,n) cin >> a[i];
    vector < vector <ll> > dp(n, vector<ll>(n));
    // dp[l][r] = X-Y for a[l...r]
    // X=Score of current player
    // Y=Score of other player
    for (int i=n-1; i>=0; --i)
    {
        for (int j=i; j<n; ++j)
        {
            if (i==j) dp[i][i]=a[i];
            else dp[i][j] = max(a[i] - dp[i+1][j], a[j]-dp[i][j-1]);

            /* For a[i...j], if player chooses left element a[i],
            *  dp[i+1][j] will then be equal to Y-X from player 1 perspective
            *  a[i]-(Y-X) = a[i] + X - Y = (a[i] + X) - Y
            *  Similarly for right element.
            */

        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}