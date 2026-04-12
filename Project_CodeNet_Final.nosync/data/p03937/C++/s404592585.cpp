#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 h, w;
    cin >> h >> w;

    i64 cnt = 0;
    for (i64 i = 0; i < h * w; i++) {
        char c;
        cin >> c;
        if (c == '#') cnt++;
    }

    cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
