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

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll dp[10101][100][2];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int d;
    string s;
    cin >> s >> d;
    int n = s.size();
    dp[0][0][0] = 1LL;

    for (int i = 0; i < n; i++)
    {
        int lim = s[i] - '0';
        for (int j = 0; j < d; j++)
        {
            // 桁を自由に決めてよいとき(flg==1)
            for (int k = 0; k < 10; k++)
            {
                (dp[i + 1][(j + k) % d][1] += dp[i][j][1]) %= MOD;
            }
            // 桁が制限されている時(flg==0)
            for (int k = 0; k <= lim; k++)
            {
                if (k == lim)
                {
                    (dp[i + 1][(j + k) % d][0] += dp[i][j][0]) %= MOD;
                }
                else
                {
                    (dp[i + 1][(j + k) % d][1] += dp[i][j][0]) %= MOD;
                }
            }
        }
    }

    cout << ((dp[n][0][0] + dp[n][0][1]) % MOD - 1LL + MOD) % MOD << endl;
}
