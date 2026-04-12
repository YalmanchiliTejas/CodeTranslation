#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

ll powmod(ll n, ll k) {
    ll r = 1, t = n % P;
    for (; k != 0; k /= 2) {
        if (k & 1) r = r * t % P;
        t = t * t % P;
    }
    return r;
}
ll inv(ll n) {
    return powmod(n, P - 2);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    auto f = [](int n, int m) {
        ll r = 0;
        for (int i = 1; i < n; i++) {
            r += (ll)i * (n - i) % P;
        }
        return r % P * m % P * m % P;
    };

    ll r = 1;

    int l = k - 2;
    for (int i = 0; i < l; i++) {
        (r *= i + 1) %= P;
    }
    r = inv(r);
    for (int i = 0; i < l; i++) {
        (r *= n * m - 2 - i) %= P;
    }

    cout << (f(n, m) + f(m, n)) % P * r % P << endl;

    return 0;
}