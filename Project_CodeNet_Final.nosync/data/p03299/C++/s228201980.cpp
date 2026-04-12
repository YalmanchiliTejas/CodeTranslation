/*
Main AC Solution(Zobiest Hash)
*/

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

const int MN = 100;
const int MH = TEN(9);

mt19937 gen;
void reseed(ll seed) {
    gen = mt19937(seed);
    for (int i = 0; i < 10000; i++) {
        gen(); // skip
    }
}

ll rand_int(ll l, ll r) { //[l, r]
    using D = uniform_int_distribution<ll>;
    assert(l <= r);
    return D(l, r)(gen);
}

string rand_lower_string(int n, int up = 26) {
    string s = "";
    for (int i = 0; i < n; i++) {
        s += 'a' + rand_int(0, up-1);
    }
    return s;
}

template<class T> void myshuffle(T &v) {
    shuffle(begin(v), end(v), gen);
}

template<uint MD>
struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll _v) : v{normS(_v % MD + MD)} {}
    explicit operator bool() const { return v != 0; }
    static uint normS(uint x) { return (x < MD) ? x : x - MD; };
    static M make(uint x) { M m; m.v = x; return m; }
    static M inv(const M& x) { return x.pow(MD - 2); }
    M operator+(const M& r) const { return make(normS(v + r.v)); }
    M operator-(const M& r) const { return make(normS(v + MD - r.v)); }
    M operator*(const M& r) const { return make(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * inv(r); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
};
using Mint = ModInt<TEN(9)+7>;

using P = pair<Mint, Mint>; // 0101, all

P make(int l, int r, V<int> &v) {
    int mi = TEN(9) + TEN(4);
    for (int i = l; i < r; i++) {
        mi = min(mi, v[i]);
    }
    for (int i = l; i < r; i++) {
        v[i] -= mi;
    }
    int other = 0;
    Mint c01 = Mint(1), c01self = Mint(1);
    int p = l;
    while (p < r) {
        if (v[p] == 0) {
            other++;
            p++;
            continue;
        }
        int q = p;
        while (q < r && v[q]) q++;
        P ch = make(p, q, v);
        c01 *= ch.first;
        c01self *= (ch.first + ch.second);
        p = q;
    }
    Mint self01 = Mint(2).pow(mi) * c01;
    Mint selfall = Mint(2).pow(other) * c01self + self01 - Mint(2) * c01;
    return P(self01, selfall);
}

int main() {
    int n;
    cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    P p = make(0, n, a);
    cout << p.second.v << endl;
    return 0;
}
