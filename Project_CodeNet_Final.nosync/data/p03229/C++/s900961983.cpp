#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int center = (n-1)/2;
    ll ans = 0;
    if (n%2 == 0) {
        for (int i=0; i<n; i++) {
            if (i < center) {
                ans -= 2 * a.at(i);
            } else if (i == center) {
                ans -= a.at(i);
            } else if (i == center + 1) {
                ans += a.at(i);
            } else {
                ans += a.at(i) * 2;
            }
        }
    } else {
        ll buf1 = 0, buf2 = 0;
        for (int i=0; i<n; i++) {
            if (i < center) {
                buf1 -= 2 * a.at(i);
            } else if (i == center || i == center + 1) {
                buf1 += a.at(i);
            } else {
                buf1 += a.at(i) * 2;
            }
        }
        for (int i=0; i<n; i++) {
            if (i < center - 1) {
                buf2 -= 2 * a.at(i);
            } else if (i == center || i == center - 1) {
                buf2 -= a.at(i);
            } else {
                buf2 += a.at(i) * 2;
            }
        }
        ans = max(buf1, buf2);
    }
    cout << ans << endl;
    return 0;
}
