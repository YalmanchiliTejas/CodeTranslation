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
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<vector<int64_t>> taro(n, vector<int64_t>(n)), jiro(n, vector<int64_t>(n));
    rep(r, n) rirep(l, r)
    {
        if (l == r) {
            taro[l][r] = a[l];
            jiro[l][r] = -a[l];
        } else {
            taro[l][r] = max(jiro[l + 1][r] + a[l], jiro[l][r - 1] + a[r]);
            jiro[l][r] = min(taro[l + 1][r] - a[l], taro[l][r - 1] - a[r]);
        }
    }
    cout << taro[0][n - 1] << endl;

    return 0;
}