#include <bits/stdc++.h>

using namespace std;

int main() {
    int mod = int(1e9) + 7;
    int n;
    cin >> n;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans = (ans + 1LL * x * sum % mod) % mod;
        (sum += x) %= mod;
    }
    cout << ans << '\n';
    return 0;
}