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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    static const int LESS = 1;
    static const int MORE = 0;

    string N;
    int K;
    cin >> N >> K;

    int n = N.size();

    s64 dp[n + 1][K + 1][2];
    rep (i, n + 1)
    {
        rep (j, K + 1)
        {
            rep (k, 2)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][MORE] = 1;
    rep (i, n)
    {
        rep (j, K + 1)
        {
            dp[i + 1][j][MORE] += (N[i] == '0') ? dp[i][j][MORE] : 0;
            dp[i + 1][j][LESS] += dp[i][j][LESS] + ((N[i] == '0') ? 0 : dp[i][j][MORE]);
            if (j != K)
            {
                dp[i + 1][j + 1][MORE] += (N[i] == '0') ? 0 : dp[i][j][MORE];
                dp[i + 1][j + 1][LESS] += dp[i][j][LESS] * 9 + ((N[i] == '0') ? 0 : dp[i][j][MORE] * (int)(N[i] - '1'));
            }
        }
    }

    cout << dp[n][K][MORE] + dp[n][K][LESS] << "\n";
    return 0;
}

