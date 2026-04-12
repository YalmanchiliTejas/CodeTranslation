#include <bits/stdc++.h>
using namespace std;
#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n"                   \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define mod 998244353
typedef long long int ll;

const int N = 3001;

ll dp[N][N];

int main()
{
    ll n;
    cin >> n;

    ll a[n];

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = a[i];
            else
            {
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
            }
        }
    }

    cout << dp[0][n - 1];
}
