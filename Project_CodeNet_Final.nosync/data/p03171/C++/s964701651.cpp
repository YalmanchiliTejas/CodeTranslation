#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define int long long
#define pb push_back
#define ld long double
#define endl "\n";
#define deb1(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define printclock cerr << "Time : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << "ms\n";
#define vii vector<int>
#define pii pair<int, int>
#define prec(n) fixed << setprecision(n)
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define MOD LLONG_MAX
#define INF 1000000007
inline void get(vector<int> &arr, int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
}
inline void print(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
/*----------------------------------TEMPLATE------------------------------------*/

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    fast;
    int t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vii v;
        get(v, n);
        vector<vii> dp(n+1, vii(n+1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if(i==j)
                {
                    dp[i][j] = v[i];
                }
                else
                {
                    dp[i][j] = max(v[i] + dp[i][j] - dp[i+1][j], v[j] + dp[i][j] - dp[i][j-1]);
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }
    printclock;
    return 0;
}