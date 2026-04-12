#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

const int mod = 998244353;
const int MAX = 1e7+1;
long long fc[MAX];
long long fci[MAX];
long long p2[MAX];

long long modpow(long long a, long long b) {
    if (a == 2 && b < MAX && p2[b]) return p2[b];
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        long long t = modpow(a, b/2);
        return (t * t) % mod;
    }
    return (a * modpow(a, b-1)) % mod;
}

void init() {
    p2[0] = 1;
    for (int i=1; i<MAX; ++i) {
        p2[i] = (p2[i-1] * 2) % mod;
    }
    fc[0] = fc[1] = 1;
    for (int i=2; i<MAX; ++i) {
        fc[i] = (fc[i-1] * i) % mod;
    }
    fci[1] = 1;
    for (int i=2; i<MAX; ++i) {
        fci[i] = (fci[i-1] * modpow(i, mod-2)) % mod;
    }
}

long long comb(long long n, long long k) {
    if (k == 0 || n == k) return 1;
    return (fc[n] * fci[k] % mod) * fci[n-k] % mod;
}

int main() {
    init();

    long long N;
    cin >> N;

    long long res = modpow(3, N);
    
    for (int i=N/2+1; i<=N; ++i) {
        long long t = (comb(N, i) * modpow(2, N-i)) % mod;
        t = (t * 2) % mod;
        res = (res - t + mod) % mod;
    }
    cout << res << endl;

    return 0;
}