#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

ll powmod(ll n, ll k) {
    ll r = 1, t = n % P;
    for (; k != 0; k /= 2) {
        if (k & 1) r = r * t % P;
        t = t * t % P;
    }
    return r;
}

int main() {
    int n;
    cin >> n;

    vector<int> inv(n / 2 + 1);
    inv[1] = 1;
    for (int i = 2; i <= n / 2; i++) {
        inv[i] = (ll)(P - P / i) * inv[P % i] % P;
    }

    ll r = 0, s = 1, t = 1;
    for (int i = n; i > n / 2; i--) {
        r += t * s % P;
        (s *= 2) %= P;
        (t *= i) %= P;
        (t *= inv[n - i + 1]) %= P;
    }
    r = powmod(3, n) - r * 2;

    r %= P;
    if (r < 0) r += P;

    cout << r << endl;

    return 0;
}