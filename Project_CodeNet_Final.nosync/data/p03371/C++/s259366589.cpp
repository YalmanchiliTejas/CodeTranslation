#define _GLIBCXX_DEBUG
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

void solve() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans1 = a * x + b * y;
    if (x > y) {
        swap(x, y);
        swap(a, b);
    }
    int ans2 = 2 * c * x + (y - x) * b;
    int ans3 = 2 * c * y;
    cout << min({ans1, ans2, ans3}) << "\n";
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}