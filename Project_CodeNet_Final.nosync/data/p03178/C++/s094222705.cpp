#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <uint MD> struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v(0) {}
    ModInt(ll _v) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
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
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using Mint = ModInt<TEN(9) + 7>;


int D;
string s;

Mint dp[10100][101][2];
bool vis[10100][101][2];
Mint solve(int p, int d, int f) {
    if (p == -1) {
        if (d == 0) return Mint(1);
        return Mint(0);
    }
    if (vis[p][d][f]) return dp[p][d][f];
    vis[p][d][f] = true;
    int c = s[p] - '0';
    Mint sm = 0;
    for (int i = 0; i <= 9; i++) {
        if (f && c < i) break;
        sm += solve(p - 1, (d + i) % D, f && (c == i));
    }
    return dp[p][d][f] = sm;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> D;
    reverse(s.begin(), s.end());
    cout << solve(int(s.size()) - 1, 0, 1) - 1 << endl;
    return 0;
}
