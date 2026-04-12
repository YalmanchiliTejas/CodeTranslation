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

    int n, m;
    cin >> n >> m;
    bool M[n][n];
    rep (i, n) rep (j, n) M[i][j] = false;

    int a, b;
    rep (i, m)
    {
        cin >> a >> b;
        --a; --b;
        M[a][b] = M[b][a] = true;
    }

    int ans = 0;
    vs32 v(n);
    rep (i, n) v[i] = i;
    do {
        bool ok = true;
        rep (i, n - 1)
        {
            int s = v[i];
            int t = v[i + 1];
            if (!M[s][t]) ok = false;
        }
        if (ok)
        {
            ++ans;
        }
    } while (next_permutation(v.begin() + 1, v.end()));

    cout << ans << "\n";
    return 0;
}

