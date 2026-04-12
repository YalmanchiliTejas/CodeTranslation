#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[3001][3001];

int main()
{
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];

    // bit = r - l としています。
    for (int bit = 0; bit < n; bit++)
    {
        for (int l = 0; l + bit < n; l++)
        {
            int r = l + bit;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}