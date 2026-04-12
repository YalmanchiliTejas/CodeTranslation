#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int main() {
    auto start = chrono::steady_clock::now();
    int n;
    cin >> n;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    auto ok = [&](i64 k) {
        vi bs(as);
        __int128_t cnt = 0;
        for (int i = 0; i < bs.size(); i++) {
            bs[i] += k;
            cnt += (bs[i] - (n - 1) + n) / (n + 1);
        }
        return cnt <= k;
    };

    i64 l = -1, r = 2e18;
    while (l < r - 1) {
        i64 m = (l + r) / 2;
        if (ok(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    
    i64 ans = r;
    while (r >= 0 && chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() < 1950) {
        if (ok(--r)) {
            ans = r;
        }
    }
    cout << ans << endl;
}