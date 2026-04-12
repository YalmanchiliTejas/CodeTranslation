#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int b = k + 1; b <= n; b++) {
        int q = (n - k) / b;
        int r = min(n - q * b, b - 1);

        ans += (ll)(b - k) * q;
        ans += r - k + 1;
    }

    if (k == 0) ans -= n;
    cout << ans << endl;
    return 0;
}