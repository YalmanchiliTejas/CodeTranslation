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

    s64 dp[s + 1][3];
    rep (i, s + 1) rep (j, 3) dp[i][j] = 0;
    dp[0][0] = 1;

    rep (i, n)
    {
        for (int j = s; j >= 0; --j)
        {
            s64 dp0, dp1, dp2;
            dp0 = dp[j][0];
            dp1 = dp[j][1];
            dp2 = dp[j][2];
            if (j >= a[i])
            {
                dp1 = (dp1 + (dp[j - a[i]][1] + dp[j - a[i]][0]) % MOD) % MOD;
                dp2 = (dp2 + (dp[j - a[i]][1] + dp[j - a[i]][0]) % MOD) % MOD;
            }
            dp1 = (dp1 + dp[j][0]) % MOD;
            dp2 = (dp2 + (dp[j][0] + dp[j][1]) % MOD) % MOD;
            dp[j][0] = dp0;
            dp[j][1] = dp1;
            dp[j][2] = dp2;
        }
    }

    cout << dp[s][2] << "\n";
    return 0;
}

