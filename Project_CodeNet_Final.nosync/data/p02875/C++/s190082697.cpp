#include <bits/stdc++.h>
using namespace std;
#define mod 998244353

long long modpow(int n, int r) {
    long long ret = 1; long long tmp = (long long) n;
    while (r != 0) {
        if (r % 2) ret *= tmp;
        tmp *= tmp; tmp %= mod; ret %= mod;
        r /= 2;
    }
    return ret;
}

long long inv(int n) {
    return modpow(n, mod-2);
}

int main() {
    int n; cin >> n;
    long long all = modpow(3, n);
    long long sub = 0;
    long long comb = 1;
    long long pow2 = 1;
    for (int i = 0; i < n/2; i++) {
        sub = (sub + (comb * pow2 % mod)) % mod;
        comb = comb * (n-i) % mod * inv(i+1) % mod;
        pow2 = pow2 * 2 % mod;
        //cout << comb << " " << sub << endl;
    }
    cout << (all + mod - sub * 2 % mod) % mod << endl;
    return 0;
}