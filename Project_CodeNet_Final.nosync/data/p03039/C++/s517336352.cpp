#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

long long MOD = 1e9 + 7;

long long Repeat(long long a, long long cnt) {
    if(cnt == 0) return 1LL;
    if(cnt % 2 == 1) {
        long long x = Repeat(a, cnt / 2);
        return (((a * x) % MOD) * x) % MOD;
    } else {
        long long x = Repeat(a, cnt / 2);
        return (x * x) % MOD;
    }
}

long long fact(long long a) {
    if(a == 0)
        return 1LL;
    else
        return (a * fact(a - 1)) % MOD;
}

long long comb(long long a, long long b) {
    long long fa, fb, fab;
    fa = fact(a);
    fb = fact(b);
    fab = fact(a - b);
    fb = Repeat(fb, MOD - 2);
    fab = Repeat(fab, MOD - 2);
    return (((fa * fb) % MOD) * fab) % MOD;
}

int main() {
    ll i, j, k, n, m;
    cin >> n >> m >> k;
    ll com;
    com = comb(n * m - 2, k - 2);
    ll kyori = 0;
    ll cnt = 0;
    for(i = 1; i < n; i++) {
        cnt += ((i*(n - i) * m % MOD) * m) % MOD;
        cnt %= MOD;
    }
    cnt = cnt * com % MOD;
    kyori += cnt;
    kyori %= MOD;
    cnt = 0;
    for(i = 1; i < m; i++) {
        cnt += ((i * (m - i) * n % MOD) * n) % MOD;
        cnt %= MOD;
    }
    kyori += (cnt * com) % MOD;
    kyori %= MOD;
    cout << kyori << endl;
    return 0;
}
