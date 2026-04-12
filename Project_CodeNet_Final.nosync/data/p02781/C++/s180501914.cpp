#include "bits/stdc++.h"
using namespace std;

#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;
#define pow10(n) int(1e##n + n)

// dp[i][j][k] …… i:確定した桁数 / j:残りの使える被ゼロ数 / k: N超でないことが確定
LL dp[101][4][2];
bool flag[101][4][2];
LL L;
string S;

LL rec(int i, int j, int isOk)
{
    if (i == L) // 被ゼロを使い切ったか？
        return (j == 0);

    if (flag[i][j][isOk])
        return dp[i][j][isOk];

    flag[i][j][isOk] = true;

    LL ans = 0;

    REP0(d, 10)
    { // d:次にえらぶやつ / nd その桁の数字
        int nd = S[i] - '0';
        int next_i = i + 1, next_j = j, next_isOk = isOk;

        if (d != 0)
            next_j--;

        if (next_j < 0)
            continue;

        if (nd < d and isOk == 0)
            continue;

        if (d < nd)
            next_isOk = true;

        ans += rec(next_i, next_j, next_isOk);
    }
    return dp[i][j][isOk] = ans;
}

void solve()
{
    cin >> S;
    L = S.length();
    int K;
    cin >> K;

    cout << rec(0, K, false) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}