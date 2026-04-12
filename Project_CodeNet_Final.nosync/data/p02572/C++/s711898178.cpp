#include <iostream>

using namespace std;

long long a[200010];

const int MOD = 1000000007;

long long modpow(long long x, long long pow) {
    if (pow == 0)return 1;
    long long ret = modpow(x, pow / 2);
    ret *= ret, ret %= MOD;
    if (pow % 2 == 1)ret *= x, ret %= MOD;
    return ret;
}

int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];

    long long count = 0;
    for (long long i = 0; i < n; i++) count += a[i], count %= MOD;
    count *= count, count %= MOD;

    long long acount = 0;
    for (long long i = 0; i < n; i++) {
        long long koo = a[i] * a[i] % MOD;
        acount -= koo;
        if (acount < 0)acount += MOD;
    }

    count += acount, count %= MOD;

    long long ret = count * modpow(2, MOD - 2);
    cout << ret % MOD << endl;
    return 0;
}