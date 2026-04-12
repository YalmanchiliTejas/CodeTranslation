#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;
ll ans;

int main() {
    cin >> n >> k;
    for (int b = k + 1; b <= n; b++) {
        ans += (b - k) * (n / b) + max((n % b) - k + 1, 0);
        if (k == 0) ans--; // (0, b)
    }
    cout << ans << endl;
    return 0;
}