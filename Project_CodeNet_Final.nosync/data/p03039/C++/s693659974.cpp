#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
#ifndef __FASTPOW_INCLUDED_
#ifndef __FASTPOW_INCLUDED_
#define __FASTPOW_INCLUDED_
template <typename T> constexpr T fpow_eq(T& x, long long y, T identity = 1) {
    for(; y > 0; x *= x, y >>= 1) if(y & 1) identity *= x;
    return x = identity;
}
template <typename T> constexpr T fpow(T x, long long y, T identity = 1) { return fpow_eq(x, y, identity); }
#endif
#endif
#ifdef __TOTIENT_INCLUDED_
template <int M, int PHI_M = phi(M)> struct modint {
#else
template <int M, int PHI_M> struct modint {
#endif
    static constexpr int MOD = M;
    int val;
    constexpr modint() : val(0) {}
    constexpr modint(int x) : val(x % M) { val += val < 0 ? M : 0; }
    constexpr modint(long long x) : modint(int(x % M)) {}
    constexpr explicit operator int() const { return val; }
    constexpr bool operator==(const modint& y) const { return val == y.val; }
    constexpr bool operator!=(const modint& y) const { return val != y.val; }
    constexpr modint& operator=(const modint& y) { val = y.val; return *this; }
    constexpr modint& operator+=(const modint& y) { val += y.val; val -= val >= M ? M : 0; return *this; }
    constexpr modint& operator-=(const modint& y) { val -= y.val; val += val <  0 ? M : 0; return *this; }
    constexpr modint& operator*=(const modint& y) { val = ll(val) * y.val % M; return *this; }
    constexpr modint& operator/=(const modint& y) { val = ll(val) * fpow(y, PHI_M - 1).val % M; return *this; }
    constexpr modint& operator^=(ll y) { fpow_eq(*this, y); return *this; }
    constexpr modint operator+(const modint& y) const { return modint(*this) += y; }
    constexpr modint operator-(const modint& y) const { return modint(*this) -= y; }
    constexpr modint operator*(const modint& y) const { return modint(*this) *= y; }
    constexpr modint operator/(const modint& y) const { return modint(*this) /= y; }
    constexpr modint operator^(ll y) const { return modint(*this) ^= y; }
    constexpr modint operator-() const { return modint(0) -= *this; }
    constexpr modint operator~() const { return modint(1) /= *this; }
    constexpr modint& operator++() { val = val == M - 1 ? 0 : val + 1; return *this; }
    constexpr modint& operator--() { val = val == 0 ? M - 1 : val - 1; return *this; }
    constexpr modint operator++(int) { modint m = *this; ++(*this); return m; }
    constexpr modint operator--(int) { modint m = *this; --(*this); return m; }
    friend constexpr modint operator+(long long x, const modint& y) { return modint(x) + y; }
    friend constexpr modint operator*(long long x, const modint& y) { return modint(x) * y; }
    friend constexpr modint operator-(long long x, const modint& y) { return modint(x) - y; }
    friend constexpr modint operator/(long long x, const modint& y) { return modint(x) / y; }
    friend ostream& operator<<(ostream& os, const modint& m) { return os << m.val; }
    friend istream& operator>>(istream& is, modint& m) { ll val; is >> val; m = modint(val); return is; }
};
constexpr int M = 1'000'000'007;
using mint = modint<M, M - 1>;
mint operator""_m(unsigned long long int x) { return mint(ll(x)); }
template <typename T = mint> T fact(int n) {
    static vector<T> fac = {1};
    while(fac.size() <= n) {
        fac.push_back(fac.back() * int(fac.size()));
    }
    return fac[n];
}
template <typename T = mint> T fact_inv(int n) {
    static vector<T> inv_fac = {1};
    while(inv_fac.size() <= n) {
        inv_fac.push_back(inv_fac.back() / int(inv_fac.size()));
    }
    return inv_fac[n];
}
template <typename T = mint> T C(int n, int k) {
    assert(n >= 0), assert(k >= 0);
    return k <= n ? fact<T>(n) * fact_inv<T>(k) * fact_inv<T>(n - k) : 0;
}
#endif
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    mint ans = 0;
    for(int gap = 1; gap < n; gap++) {
        ans += C(n * m - 2, k - 2) * (n - gap) * m * m * gap;
    }
    for(int gap = 1; gap < m; gap++) {
        ans += C(n * m - 2, k - 2) * (m - gap) * n * n * gap;
    }
    cout << ans << endl;
    return 0;
}