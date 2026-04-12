#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
long long a[200020];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = ans + (a[i] * a[i - 1] % mod);
        a[i] += a[i - 1];
        a[i] %= mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}