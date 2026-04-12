#include <algorithm>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif
using namespace std;

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

const int MAXN = 55;
llong N;
llong nums[MAXN];

llong perform(llong K)
{
    llong res = 0;
    FO (i, N)
    {
        llong diff = nums[i] + K - (N - 1);
        if (diff > 0)
            res += diff / (N + 1) + bool(diff % (N + 1));
    }
    return res;
}

int main()
{
    while (cin >> N)
    {
        FO (i, N)
            cin >> nums[i];
        llong lo = 0, hi = 50e16 + 100;
        while (lo < hi)
        {
            llong mid = lo + (hi - lo) / 2;
            llong cnt = perform(mid);
            if (cnt == mid)
            {
                lo = mid;
                break;
            }
            else if (cnt > mid)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        for (llong i = max(lo - 10000, 0LL); i <= hi + 10000; ++i)
            if (perform(i) == i)
            {
                cout << i << endl;
                break;
            }
    }
    return 0;
}