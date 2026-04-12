#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define pii pair < int , int >
#define pll pair < long long, long long >

const int N = 200005;


int main()
{
    #ifdef Estb_probitie
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    int a[n + 2];
    ll pref[n + 2] = {};

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    pref[0] = a[0];
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + a[i];

    ll dp[n + 2][n + 2];

    for (int j = 0; j < n; ++j)
        dp[j][j] = a[j];

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
            {
                ll zn = 0;
                if (j)
                    zn = pref[j - 1];

                ll ma1 = pref[i + j - 1] - zn - dp[j][i + j - 1] + a[j + i];
                ll ma2 = pref[i + j] - pref[j] - dp[j + 1][i + j] + a[j];

                dp[j][i + j] = max(ma1, ma2);
            }
    }

    cout << dp[0][n - 1]*2 - pref[n - 1];
}
