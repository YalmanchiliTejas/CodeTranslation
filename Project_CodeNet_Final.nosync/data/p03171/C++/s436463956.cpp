#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mst(a, b) memset((a), (b), sizeof(a))
#define mp(a, b) make_pair(a, b)
#define pi acos(-1)
#define pii pair<int, int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int maxn = 3e3 + 7;
const int maxm = 5e5 + 10;
const int mod = 1e9 + 7;
ll dp[maxn][maxn];
ll s[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = n; i > 0; --i)
    {
        for (int j = i; j <= n; ++j)
        {
            dp[i][j] = max(s[i] - dp[i + 1][j], s[j] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}