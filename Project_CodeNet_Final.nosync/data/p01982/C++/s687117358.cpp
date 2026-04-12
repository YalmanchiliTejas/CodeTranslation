#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

void _main() {
    int n, l, r;
    while (cin >> n >> l >> r, n) {
        vector<int> A(n);
        REP (i, n) cin >> A[i];
        A.push_back(1);
        int ans = 0;
        FOR (y, l, r + 1) {
            REP (i, A.size()) {
                if (y % A[i] == 0) {
                    if (i % 2 == 0) ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
