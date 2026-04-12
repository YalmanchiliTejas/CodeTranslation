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

s64 N, X;
s64 rec(s64 n, s64 x)
{
    if (n == 0 && x == 1) return 1;

    s64 len = ((s64)1 << (n + 1)) - (s64)3;
    s64 num = ((s64)1 << n) - (s64)1;
    s64 ret = 0;
    if (x == 0) return 0;
    else if (x <= 1 + len)
    {
        ret = rec(n - 1, x - 1);
    }
    else if (x == 2 + len)
    {
        ret = rec(n - 1, x - 1) + 1;
    }
    else if (x <= 2 + 2 * len)
    {
        ret = num + 1 + rec(n - 1, x - 2 - len);
    }
    else
    {
        ret = 2 * num + 1;
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> X;
    cout << rec(N, X) << "\n";
    return 0;
}

