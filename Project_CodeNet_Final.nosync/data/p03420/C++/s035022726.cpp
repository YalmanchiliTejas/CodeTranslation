#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int b = k + 1; b <= n; b++) {
        ans += (ll)(n / b) * (b - k);
        int tmp = n % b;
        ans += max(tmp - k + (k != 0), 0);
    }
    cout << ans << endl;
    return 0;
}