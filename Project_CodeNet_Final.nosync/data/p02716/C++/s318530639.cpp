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
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vs64 a(n);
    rep (i, n) cin >> a[i];

    const s64 inf = 1e18;
    vector< vector< vs64 > > dp(n + 1, vector< vs64 >(3, vs64(2, -inf)));
    rep (i, 2) dp[0][i + 1][0] = 0;

    rep (i, n)
    {
        if (i % 2 == 0)
        {
            dp[i + 1][0][0] = dp[i][0][0];
            dp[i + 1][1][0] = max(dp[i][1][1], dp[i][1][0]);
            dp[i + 1][1][1] = dp[i][0][0] + a[i];
            dp[i + 1][2][1] = dp[i][1][0] + a[i];
        }
        else
        {
            dp[i + 1][0][0] = max(dp[i][1][0], dp[i][1][1]);
            dp[i + 1][1][0] = max(dp[i][2][0], dp[i][2][1]);
            dp[i + 1][0][1] = dp[i][0][0] + a[i];
            dp[i + 1][1][1] = dp[i][1][0] + a[i];
            dp[i + 1][2][1] = dp[i][1][0] + a[i];
        }
    }

    cout << max(dp[n][1][0], dp[n][1][1]) << "\n";
    return 0;
}

