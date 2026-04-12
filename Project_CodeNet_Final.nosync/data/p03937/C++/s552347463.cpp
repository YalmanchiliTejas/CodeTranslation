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

vector< string > field;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    field.resize(h);
    rep (i, h) cin >> field[i];

    int num = 0;
    rep (i, h) rep (j, w) num += field[i][j] == '#';

    auto check = [](int x) {
        int ret = 0;
        while (x)
        {
            ret += x & 1;
            x >>= 1;
        }
        return ret;
    };

    bool ans = false;
    rep (i, 1 << (h + w - 2))
    {
        if (check(i) != h - 1) continue;
        int temp = i;
        int y, x;
        x = y = 0;
        int cnt = field[y][x] == '#';
        rep (j, h + w - 2)
        {
            if ((temp >> j) & 1) ++y;
            else ++x;
            if (field[y][x] == '#') ++cnt;
        }
        if (num == cnt) ans = true;
    }

    cout << (ans ? "Possible\n" : "Impossible\n");
    return 0;
}

