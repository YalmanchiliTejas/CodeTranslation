#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)
#define pow10(n) int(1e##n + n)

typedef long long LL;
typedef pair<int, int> P;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e17) + 1;
long double eps = 1.0E-14;
// dp[i][j] i番目までに, 「余分な空白」を j 個挟んだとしたときの和の最大値
LL dp[2 * pow10(5)][3];

void solve()
{
    int N;
    cin >> N;
    vector<LL> A(N);
    REP0 (i, N)
    {
        cin >> A[i];
        REP0 (j, 3)
        {
            dp[i][j] = -LLINF;
        }
    }

    if (N % 2 == 0)
    {
        dp[0][0] = A[0];
        dp[1][0] = A[0];
        dp[1][1] = A[1];
        LL ans = -LLINF;

        for (int i = 2; i < N; i++)
        {
            dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i]);
            if (i - 3 >= 0)
                dp[i][1] = max(dp[i][1], dp[i - 3][0] + A[i]);

            dp[i][0] = max(dp[i][0], dp[i - 2][0] + A[i]);
        }

        // ans = max(ans, dp[N - 1][0]);
        ans = max(ans, dp[N - 1][1]);
        ans = max(ans, dp[N - 2][0]);

        std::cout << ans << endl;
        return;
    }

    dp[0][0] = dp[1][0] = A[0];
    dp[1][1] = A[1];
    dp[2][0] = dp[0][0] + A[2];
    dp[2][2] = A[2];
    LL ans = -LLINF;

    for (int i = 3; i < N; i++)
    {
        dp[i][2] = max(dp[i][2], dp[i - 2][2] + A[i]);
        dp[i][2] = max(dp[i][2], dp[i - 3][1] + A[i]);
        if (i - 4 >= 0)
            dp[i][2] = max(dp[i][2], dp[i - 4][0] + A[i]);

        dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i]);
        dp[i][1] = max(dp[i][1], dp[i - 3][0] + A[i]);

        dp[i][0] = max(dp[i][0], dp[i - 2][0] + A[i]);
    }

    // ans = max(ans, dp[N - 1][0]);
    // ans = max(ans, dp[N - 1][1]);
    ans = max(ans, dp[N - 1][2]);

    ans = max(ans, dp[N - 2][1]);

    ans = max(ans, dp[N - 3][0]);

    std::cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
