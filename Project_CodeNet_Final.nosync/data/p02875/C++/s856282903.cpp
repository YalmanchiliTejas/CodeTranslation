#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 1E7 + 5;

int n;
long long ans = 1, pw[N], inv[N], fct[N], ifc[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    fct[0] = ifc[0] = pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        fct[i] = fct[i - 1] * i % MOD;
        ifc[i] = ifc[i - 1] * inv[i] % MOD;
        pw[i] = pw[i - 1] * 2 % MOD;
        (ans *= 3) %= MOD;
    }
    for (int i = n / 2 + 1; i <= n; i++) {
        long long cur = fct[n] * ifc[i] % MOD * ifc[n - i] % MOD;
        (cur *= pw[n - i] * 2) %= MOD;
        (ans += MOD - cur) %= MOD;
    }
    cout << ans;
}
