#include <bits/stdc++.h>
#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

int64_t g(int64_t len, int64_t k) {
    auto tmp = 1;
    for (auto j : irange(0L, k)) {
        tmp *= 9;
    }
    for (auto j : irange(0L, k)) {
        tmp *= len - j;
    }
    for (auto j : irange(0L, k)) {
        tmp /= (j + 1);
    }
    return tmp;
}

int main() {
    string n;
    cin >> n;

    int64_t k;
    cin >> k;

    int64_t ans = 0;
    int64_t r = 0;
    for (auto i : irange(0uL, n.size())) {
        if (r > k) {
            break;
        }
        if (n[i] != '0') {
            int64_t len = n.size() - i - 1;
            if (len >= k - r) {
                ans += g(len, k - r);
            }
            if (k - r > 0 && len >= k - r - 1) {
                ans += (n[i] - '1') * g(len, k - r - 1);
            }
            ++r;
        }
    }
    if (r == k) {
        ++ans;
    }
    cout << ans << endl;
}
