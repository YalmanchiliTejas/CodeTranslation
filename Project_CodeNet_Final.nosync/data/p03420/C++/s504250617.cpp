#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long ans = 0;
    for (int i = k + 1; i <= n; i++) {
        ans += (n / i) * (i - k);
        ans += max(0, n % i - max(0, k - 1));
    }
    cout << ans << endl;
    return 0;
}
