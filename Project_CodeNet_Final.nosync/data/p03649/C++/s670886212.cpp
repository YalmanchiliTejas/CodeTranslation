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

int64_t dceil(int64_t, int64_t);
int64_t dfloor(int64_t, int64_t);

int64_t dceil(int64_t x, int64_t y)
{
    if (y < 0) {
        return dceil(-x, -y);
    }
    if (x < 0) {
        return -dfloor(-x, y);
    }
    return (x + y - 1) / y;
}

int64_t dfloor(int64_t x, int64_t y)
{
    if (y < 0) {
        return dfloor(-x, -y);
    }
    if (x < 0) {
        return -dceil(-x, y);
    }
    return x / y;
}

int main()
{
    int n;
    cin >> n;
    vector<int64_t> a(n);

    int64_t s = 0;
    rep(i, n)
    {
        cin >> a[i];
        s += a[i];
    }

    for (int64_t i = max(s - n * (n - 1), 0L); i <= s; i++) {
        int64_t t = 0;
        rep(j, n)
        {
            t += dceil(a[j] + i - (n - 1), n + 1);
        }
        if (t == i) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}