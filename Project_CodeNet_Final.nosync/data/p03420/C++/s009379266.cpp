#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }

    long long ans = 0;
    for (long long b = k + 1; b <= n; ++b) {
        ans += (n / b) * (b - k) + fmax(0, n % b - k + 1);
    }

    cout << ans << endl;
    return 0;
}