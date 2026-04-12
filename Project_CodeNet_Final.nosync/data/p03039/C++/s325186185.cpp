#include<bits/stdc++.h>
using namespace std;

constexpr long mod = 1000000007;

long inv(long x) {
    long r = 1;
    long y = mod-2;
    while(y) {
        if(y&1) r *= x, r %= mod;
        x *= x, x %= mod;
        y >>= 1;
    }
    return r;
}

long comb(long x, long y) {
    long r = 1, s = 1;
    for(long i=0; i<y; i++)
        r *= x-i, r %= mod;
    for(long i=0; i<y; i++)
        s *= i+1, s %= mod;
    return r * inv(s) % mod;
}

long fact(long x) {
    long r = 1;
    for(long i=1; i<=x; i++)
        r *= i, r %= mod;
    return r;
}

int main(void) {
    long n, m ,k;
    cin >> n >> m >> k;

    long sum = 0;
    
    for(long x=0; x<m; x++) {
        long a;
        a = x*(x+1)/2, a %= mod;
        a = a * n, a %= mod;
        sum += a * n, sum %= mod;

        a = (m-1-x)*(m-1-x+1)/2 % mod;
        a = a * n, a %= mod;
        sum += a * n, sum %= mod;
    }

    for(long y=0; y<n; y++) {
        long a;
        a = y*(y+1)/2 % mod;
        a = a * m, a %= mod;
        sum += a * m, sum %= mod;

        a = (n-1-y)*(n-1-y+1)/2 % mod;
        a = a * m, a %= mod;
        sum += a * m, sum %= mod;
    }

    long r = 1;
    r *= sum, r %= mod;
    r *= comb(n*m-2, k-2), r %= mod;
    r *= inv(2), r %= mod;
    cout << r << endl;
}
