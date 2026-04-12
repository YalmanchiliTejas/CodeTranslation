#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = (int)1e9 + 7;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, m, k;
int fac[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    fac[0] = 1;
    for (int i = 1; i <= n * m; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    int delta = mul(fac[n * m - 2], inv(mul(fac[k - 2], fac[n * m - k])));
    auto get = [&](int n, int m) {
        int res = mul(m, m);
        res = mul(res, n - 1);
        res = mul(res, n);
        res = mul(res, n + 1);
        res = mul(res, inv(6));
        return res;
    };
    int res = add(get(n, m), get(m, n));
    res = mul(res, delta);
    cout << res << endl;
    return 0;
}