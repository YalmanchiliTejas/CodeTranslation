#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) cin >> data[i];
    int suma = 0;
    for (int i = 0; i < n; ++i) suma = (suma + data[i]) % MOD;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        suma -= data[i];
        if (suma < 0) suma += MOD;
        suma %= MOD;
        ans += (suma * data[i]) % MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
