#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[n];
    long long s;
    long long mod(1e9 + 7);
    long long ans(0);
    for (int i = 0; i < n; ++i) {
            cin >> a[i];
        s += a[i];
        s %= mod;
    }
    for (int i = 0; i < n; ++i) {
        s -= a[i];
        s += mod;
        s %= mod;
        ans += s * a[i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
};