#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

const long double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    int n;
    cin >> n;

    ll a[n];
    ll wa = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        wa += a[i];
        wa = wa % MOD;
    }

    ll ans = wa * wa % MOD;
    for(int i = 0; i < n; i++) ans = (ans + MOD*MOD - a[i]*a[i]) % MOD;

    ans = ans * modinv(2, MOD) % MOD;

    cout << ans << endl;

    return 0;
}