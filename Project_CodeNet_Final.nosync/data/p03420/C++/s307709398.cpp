#include <bits/stdc++.h>
using namespace std;

#define repeat(i, x) for (int64_t i = 0; (i) < (int64_t)(x); (i)++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int64_t n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }

    int64_t ans = 0;
    for (int64_t b = 1; b <= n; b++) {
        ans += (n / b) * max(b - k, (int64_t)0);

        if (k > 0) {
            ans += max((n % b + 1) - k, (int64_t)0);
        }
        // cerr << "b: " << b << " cnt: " << (n / b) * max(b - k, 0) + max(n % b - k, 0) << endl;
    }

    cout << ans << endl;

    return 0;
}
