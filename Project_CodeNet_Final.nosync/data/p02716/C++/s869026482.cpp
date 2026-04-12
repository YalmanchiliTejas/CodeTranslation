#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#include <numeric>

using namespace std;

#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)

using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

ll power(long a, long b) { return b ? power(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int A[200100];
    rep(i, N)
            cin >>
        A[i];

    long dp[200100][2][3];
    rep(i, N + 1) rep(x, 2) rep(y, 3) dp[i][x][y] = -1LL << 60;
    dp[0][1][0] = 0;
    for (int i = 0; i < N; i++)
    {
        rep(j, 2) rep(k, 3)
        {
            // not take
            if (k + j < 3)
                dp[i + 1][1][k + j] = max(dp[i + 1][1][k + j], dp[i][j][k]);
            // take
            if (j == 1)
                dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][j][k] + A[i]);
        }
    }
    if (N % 2 == 0)
        cout << max(dp[N][1][0], dp[N][0][1]) << "\n";
    else
        cout << max(dp[N][0][2], dp[N][1][1]) << "\n";
}