#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define sz(x) ((long long)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const ld eps = 1e-9;
const ld pi = acosl(-1);
const int mod = 998244353;
const int mod1 = 1e9 + 7;

mt19937_64 rnd(time(0));

void faster()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}

signed main() {
    faster();
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    //______________________________________
    /*__*/double start = clock();/*__*/
    //_____________________________________
    int n;
    cin >> n;
    int a[n];
    pair <int, int> dp[n][n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = {a[i], 0};
    }
    for (int szq = 1; szq < n; szq++)
    {
        for (int l = 0; l + szq < n; l++)
        {
            int r = l + szq;
            if (dp[l][r - 1].second + a[r] > dp[l + 1][r].second + a[l])
            {
                dp[l][r] = {dp[l][r - 1].second + a[r], dp[l][r - 1].first};
            }
            else
                dp[l][r] = {dp[l + 1][r].second + a[l], dp[l + 1][r].first};
            //  cout << l << " " << r << ' ' << dp[l][r].first << " " <<dp[l][r].second << endl;
        }
    }
    auto ans = dp[0][n - 1];
    cout << ans.first - ans.second;
    //______________________________________
    cerr << "Time " << (clock() - start)  * 1.0 / CLOCKS_PER_SEC << "s\n";
    return 0;
}