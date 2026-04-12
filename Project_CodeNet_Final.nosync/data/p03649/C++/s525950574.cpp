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
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll ans = 0;
    while (true) {
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i] / n;
            a[i] = a[i] % n - a[i] / n;
        }
        if (s == 0) break;
        for (int i = 0; i < n; ++i) {
            a[i] += s;
        }
        ans += s;
    }
    cout << ans << endl;
    return 0;
}