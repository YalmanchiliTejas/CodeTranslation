#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long mod_pow(long x, int k) {
    long ret = 1;
    while (k > 0) {
        if (k & 1)
            ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        k >>= 1;
    }
    return ret;
}

long inv(long x) {
    return mod_pow(x, MOD - 2);
}

long combi(long n, long r) {
    long ret = 1;
    for (long i = 0; i < r; i++) {
        ret *= n - i;
        ret %= MOD;
        ret *= inv(i + 1);
        ret %= MOD;
    }
    return ret;
}

int main() {
    long n, m, k;
    cin >> n >> m >> k;
    long ans = (n * n * (m + 1) * m * (m - 1) + m * m * (n + 1) * n * (n - 1)) / 6 % MOD;
    ans = (ans * combi(n * m - 2, k - 2)) % MOD;
    cout << ans << endl;
    return 0;
}
