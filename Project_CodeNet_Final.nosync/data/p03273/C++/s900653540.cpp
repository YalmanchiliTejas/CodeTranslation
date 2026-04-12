#include <bits/stdc++.h>  // clang-format off
using namespace std;
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Fri Mar 27 18:29:10 JST 2020
 **/

signed main() {
    Int H, W;
    cin >> H >> W;
    vector<string> a(H);
    REP(i, H) cin >> a[i];
    vector<Int> rows, cols;
    REP(i, H) {
        bool ok = false;
        REP(j, W) {
            if (a[i][j] == '#') ok = true;
        }
        if (ok) rows.push_back(i);
    }
    REP(j, W) {
        bool ok = false;
        REP(i, H) {
            if (a[i][j] == '#') ok = true;
        }
        if (ok) cols.push_back(j);
    }
    for (Int i : rows) {
        for (Int j : cols) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
