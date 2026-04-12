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

vector<int> f0, f1;
void init(int n) {
    f0.resize(n + 1);
    f0[0] = 1;
    for (int i = 1; i <= n; i++) {
        f0[i] = (ll)f0[i - 1] * i % P;
    }
    f1.resize(n + 1);
    f1[n] = inv(f0[n]);
    for (int i = n; i > 0; i--) {
        f1[i - 1] = (ll)f1[i] * i % P;
    }
}
ll fact(int k) {
    return f0[k];
}
ll comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return (ll)f0[n] * f1[k] % P * f1[n - k] % P;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    s = '0' + s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        s[i] -= '0';
    }
    s[n - 1] += 1;
    for (int i = n - 1; i > 0; i--) {
        if (s[i] >= 10) s[i] -= 10, s[i - 1]++;
    }

    init(n);

    int r = 0;
    for (int i = 0; i < n; i++) {
        int l = k;
        for (int j = 0; j < i; j++) {
            l -= s[j] > 0;
        }
        if (l < 0) continue;
        if (l == 0) {
            if (s[i] > 0) r++;
            continue;
        }

        int t = 1;
        for (int x = 0; x < l; x++) {
            t *= 9;
        }
        if (s[i] > 0) r += comb(n - 1 - i, l) * t;
        if (s[i] > 1) r += (s[i] - 1) * comb(n - 1 - i, l - 1) * t / 9;
    }

    cout << r << endl;

    //456なら、400未満と450未満と456未満

    return 0;
}