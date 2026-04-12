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

s64 modpow(s64 x, s64 n, s64 mod)
{
    s64 ret = 1;
    while (n)
    {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vs64 a(n);
    rep (i, n) cin >> a[i];

    s64 sum1 = 0;
    s64 sum2 = 0;
    s64 squaredsum;
    s64 ans;
    rep (i, n)
    {
        sum1 = (sum1 + a[i]) % MOD;
        sum2 = (sum2 + a[i] * a[i] % MOD) % MOD;
    }

    squaredsum = (sum1 * sum1) % MOD;

    ans = (squaredsum + (MOD - sum2)) % MOD * modpow(2, MOD - 2, MOD) % MOD;

    cout << ans << "\n";
    return 0;
}

