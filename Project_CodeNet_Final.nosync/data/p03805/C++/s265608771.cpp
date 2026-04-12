#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

// dp[S][v] := 頂点0から出発して、集合Sに含まれる頂点をすべて訪れるpath
// のうち、頂点vが最後になるようなpathの総数
ll dp[2000][20];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    dp[1][0] = 1;

    for (int S = 1; S < (1 << n); S++)
    {
        for (int v = 0; v < n; v++)
        {
            if ((S & (1 << v)) == 0)
            {
                continue;
            }
            int sub = (S ^ (1 << v));
            for (int u = 0; u < n; u++)
            {
                if ((sub & (1 << u)) && g[v][u] == 1)
                {
                    dp[S][v] += dp[sub][u];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += dp[(1 << n) - 1][i];
    }
    cout << ans << endl;
}