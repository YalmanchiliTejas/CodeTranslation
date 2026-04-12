#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cout.precision(20);

    int n, k;
    cin >> n >> k;

    int ans = 0;

    if (k == 0) {
        for (int i = 1; i <= n; ++i) {
            ans += n / i;
        }
        k = 1;
    }

    for (int i = k + 1; i <= n; ++i) {
        ans += (n / i) * (i - k);
        if (k <= n % i) ans += n % i - k + 1;
    }

    cout << ans << '\n';
    return 0;
}