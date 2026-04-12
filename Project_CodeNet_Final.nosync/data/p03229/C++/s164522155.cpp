#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    sort(begin(a), end(a));

    i64 h = n / 2;
    if (n % 2) {
        i64 can0 = 0;
        can0 -= 2 * accumulate(begin(a), begin(a) + h, 0l);
        can0 += 2 * accumulate(begin(a) + h, end(a), 0l) - a[h] - a[h + 1];
        i64 can1 = 0;
        can1 -= 2 * accumulate(begin(a), begin(a) + n - h, 0l) - a[h] - a[h - 1];
        can1 += 2 * accumulate(begin(a) + n - h, end(a), 0l);
        cout << max(can0, can1) << endl;
    } else {
        i64 ans = 0;
        ans -= 2 * accumulate(begin(a), begin(a) + h, 0l) - a[h - 1];
        ans += 2 * accumulate(begin(a) + h, end(a), 0l) - a[h];
        cout << ans << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
