#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 0, ans2 = 0;
    vector<ll> c(n);

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (i == 0 || i == n - 1)
                c[i] = 1;
            else
                c[i] = 2;
        } else {
            if (i == 0 || i == n - 1)
                c[i] = -1;
            else
                c[i] = -2;
        }
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        ans += a[i] * c[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (i == 0 || i == n - 1)
                c[i] = -1;
            else
                c[i] = -2;
        } else {
            if (i == 0 || i == n - 1)
                c[i] = 1;
            else
                c[i] = 2;
        }
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        ans2 += a[i] * c[i];
    }

    cout << max(ans, ans2) << endl;
    return 0;
}