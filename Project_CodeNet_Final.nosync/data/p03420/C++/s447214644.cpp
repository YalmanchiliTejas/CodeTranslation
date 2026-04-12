#include <bits/stdc++.h>

using namespace std;
long long ans;
int n, k;
int main() {
    cin >> n >> k;
    if (k == 0) {
        cout << (1LL * n * n);
        return 0;
    }
    for (int b = 1; b <= n; b++) {
        if (b - 1 < k) continue;
        int nn = n;
        if (nn % b < k) nn = b * (nn / b);
        else ans += (nn % b - k + 1);
        nn = b * (nn / b);
        ans += (nn / b) * (b - 1 - k + 1);
    }
    cout << ans;
    return 0;
}
