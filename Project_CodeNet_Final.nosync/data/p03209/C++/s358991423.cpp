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

vu64 l;
vu64 p;

u64 solve(u64 n, u64 x)
{
    u64 ret = 0;
    if (n == 0)
    {
        ret = p[0];
    }
    else if (x <= 1)
    {
        ret = 0;
    }
    else if (2 <= x && x <= l[n - 1] + 1)
    {
        ret = solve(n - 1, x - 1);
    }
    else if (l[n - 1] + 2 == x)
    {
        ret = p[n - 1] + 1;
    }
    else if (l[n - 1] + 3 <= x && x <= 2 * l[n - 1] + 2)
    {
        ret = solve(n - 1, x - l[n - 1] - 2) + p[n - 1] + 1;
    }
    else if (x == l[n])
    {
        ret = p[n];
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    u64 N, X;
    cin >> N >> X;

    l.resize(N + 1);
    p.resize(N + 1);

    l[0] = p[0] = 1;
    rep (i, N)
    {
        l[i + 1] = 2 * l[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }

    cout << solve(N, X) << "\n";
    return 0;
}

