#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    x *= 2;
    y *= 2;

    int result = numeric_limits<int>::max();
    irep(k, max(x, y))
    {
        int i = max(0L, (x - k + 1) / 2), j = max(0L, (y - k + 1) / 2);
        int cost = a * i + b * j + c * k;
        result = min(result, cost);
    }
    cout << result << endl;

    return 0;
}