#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

ll dp[10001][101][2];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    int D;
    cin >> s >> D;
    int N = s.length();
    dp[0][0][1] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            int num = s[i] - '0';
            dp[i + 1][(j + num) % D][1] += dp[i][j][1];
            dp[i + 1][(j + num) % D][1] %= MOD;
            for (int k = 0; k < num; k++)
            {
                dp[i + 1][(j + k) % D][0] += dp[i][j][1];
                dp[i + 1][(j + k) % D][0] %= MOD;
            }
            for (int k = 0; k <= 9; k++)
            {
                dp[i + 1][(j + k) % D][0] += dp[i][j][0];
                dp[i + 1][(j + k) % D][0] %= MOD;
            }
        }
    }
    ll res = dp[N][0][0] + dp[N][0][1] - 1;
    res = (res + MOD) % MOD;
    cout << res << endl;
}
