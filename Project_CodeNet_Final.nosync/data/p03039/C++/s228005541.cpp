#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1e16
#define MAX_N 200000
const long long MOD = 1e9 + 7;

long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}
long long mod_inverse(long long a, long long m) {
    long long x, y;
    if (extgcd(a, m, x, y) == 1)
        return (m + x % m) % m;
    else
        return -1;
}
vector<long long> fact(MAX_N + 1, INF);
long long mod_fact(long long n, long long& e) {
    if (fact[0] == INF) {
        fact[0] = 1;
        if (MAX_N != 0) fact[1] = 1;
        for (int i = 2; i <= MAX_N; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
    }
    e = 0;
    if (n == 0) return 1;
    long long res = mod_fact(n / MOD, e);
    e += n / MOD;
    if ((n / MOD) % 2 != 0) return (res * (MOD - fact[n % MOD])) % MOD;
    return (res * fact[n % MOD]) % MOD;
}

long long mod_comb(long long n, long long k) {
    if (n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2),
              a3 = mod_fact(n - k, e3);
    if (e1 > e2 + e3) return 0;
    return (a1 * mod_inverse((a2 * a3) % MOD, MOD)) % MOD;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    ll sum = 0;
    ll num = mod_comb(N * M - 2, K - 2);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ll tmpx = (1 + N - i) * (N - i) / 2 % MOD;
            tmpx = (tmpx * M * num) % MOD;
            sum = (sum + tmpx) % MOD;

            ll tmpy = (1 + M - j) * (M - j) / 2 % MOD;
            tmpy = (tmpy * N * num) % MOD;
            sum = (sum + tmpy) % MOD;
        }
    }
    cout << sum << endl;
}