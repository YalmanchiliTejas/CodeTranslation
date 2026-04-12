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
    ll n, k;
    cin >> n >> k;
    if (k == 0)
        cout << n * n << endl;
    else {
        ll ans = 0;
        for (ll b = k + 1; b <= n; ++b) {
            ans += (n + 1) / b * (b - k) + max(0LL, (n + 1) % b - k);
        }
        cout << ans << endl;
    }
    return 0;
}