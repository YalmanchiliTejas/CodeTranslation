#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 998244353;

struct mint {
    lint v;
    lint _mod;
    mint() : v(0) {}
    mint(signed v, lint _mod = mod) : v(v), _mod(_mod) {}
    mint(lint t, lint _mod = mod) : _mod(_mod) {
        v = t % _mod;
        if (v < 0)
            v += _mod;
    }

    mint pow(lint k) {
        mint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static mint add_identity() { return mint(0); }
    static mint mul_identity() { return mint(1); }
    mint inv() { return pow(_mod - 2); }

    mint &operator+=(mint a) {
        v += a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator-=(mint a) {
        v += _mod - a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator*=(mint a) {
        v = v * a.v % _mod;
        return *this;
    }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }

    mint operator+(mint a) const { return mint(v) += a; };
    mint operator-(mint a) const { return mint(v) -= a; };
    mint operator*(mint a) const { return mint(v) *= a; };
    mint operator/(mint a) const { return mint(v) /= a; };

    mint operator-() const { return v ? mint(_mod - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }
};
ostream &operator<<(ostream &os, mint m) { return os << m.v; }

struct Combination {
    vector<lint> fac, finv, inv;
    Combination(lint maxN) : fac(maxN + 100), finv(maxN + 100), inv(maxN + 100) {
        maxN += 100; // for safety
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1]            = 1;
        for (lint i = 2; i <= maxN; ++i) {
            fac[i]  = fac[i - 1] * i % mod;
            inv[i]  = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint operator()(lint n, lint k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint n;
    cin >> n;
    Combination nCk(n);
    mint ng = 0;
    for (int i = n / 2 + 1; i <= n; ++i) {
        ng += mint(2).pow(n - i) * nCk(n, i);
    }
    cout << mint(3).pow(n) - ng * 2 << "\n";
    return 0;
}