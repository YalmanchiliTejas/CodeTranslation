#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAX_N 200010
long long inv[MAX_N];
long long factorial[MAX_N];
long long inv_factorial[MAX_N];

void GetInv(){
    for (int i = 1; i < MAX_N; i++) {
        if (i == 1) inv[i] = 1;
        else {
            inv[i] = (mod - (mod / i) * inv[mod % i]) % mod;
            if (inv[i] < 0) inv[i] += mod;
        }
    }
}
void GetFactorial(){
    factorial[0] = 1; inv_factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        factorial[i] = factorial[i-1] * i;
        factorial[i] %= mod;
        inv_factorial[i] = inv_factorial[i-1] * inv[i];
        inv_factorial[i] %= mod;
    }
}

long long combination(int n, int r) {
    long long ret = factorial[n] * inv_factorial[r];
    ret %= mod;
    ret *= inv_factorial[n-r];
    return ret % mod;
}

long long modpow(int n, int r) {
    long long ret = 1; long long tmp = (long long) n;
    while (r != 0) {
        if (r % 2) ret *= tmp;
        tmp *= tmp; tmp %= mod; ret %= mod;
        r /= 2;
    }
    return ret;
}

long long calc(long long n, long long m) {
    long long ret = 0;
    for (long long i = 0; i < n; i++) {
        ret += i * (n-i);
        ret %= mod;
    }
    ret = ret * m % mod * m % mod;
    return ret;
}

int main() {
    GetInv(); GetFactorial();
    int n, m, k; cin >> n >> m >> k;
    long long ans = calc(n, m) + calc(m, n);
    ans %= mod;
    ans = ans * combination(n*m-2, k-2) % mod;
    cout << ans << endl;
    return 0;
}