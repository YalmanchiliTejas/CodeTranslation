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

    int n;
    cin >> n;

    vs32 ans(26, (int)1e9);
    string s;
    rep (i, n)
    {
        cin >> s;
        vs32 temp(26, 0);
        rep (i, s.size())
        {
            ++temp[s[i] - 'a'];
        }
        rep (i, 26)
        {
            ans[i] = MIN(ans[i], temp[i]);
        }
    }

    string t = "";
    rep (i, 26)
    {
        t += string(ans[i], (char)('a' + (char)i));
    }
    cout << t << "\n";
    return 0;
}

