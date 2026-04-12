#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <numeric>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 998244353ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    s64 n, s;
    cin >> n >> s;
    vs64 a(n);
    rep (i, n) cin >> a[i];

    s64 dp[n + 1][s + 1][3];
    rep (i, s + 1) rep (j, 3) dp[0][i][j] = 0;
    dp[0][0][0] = 1;

    rep (i, n)
    {
        rep (j, s + 1)
        {
            if (j >= a[i])
            {
                dp[i + 1][j][0] = dp[i][j][0];
                dp[i + 1][j][1] = (dp[i][j][1] + (dp[i][j - a[i]][1] + (i + 1) * dp[i][j - a[i]][0] % MOD)) % MOD % MOD;
                dp[i + 1][j][2] = (dp[i][j][2] + ((n - i) * dp[i][j - a[i]][1] % MOD + (i + 1) * (n - i) * dp[i][j - a[i]][0] % MOD) % MOD) % MOD;
            }
            else
            {
                dp[i + 1][j][0] = dp[i][j][0];
                dp[i + 1][j][1] = dp[i][j][1];
                dp[i + 1][j][2] = dp[i][j][2];
            }
        }
    }

    cout << dp[n][s][2] << "\n";
    return 0;
}

