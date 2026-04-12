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
#ifndef __FASTPOW_INCLUDED_
#define __FASTPOW_INCLUDED_
template <typename T> constexpr T fpow_eq(T& x, long long y, T identity = 1) {
    for(; y > 0; x *= x, y >>= 1) if(y & 1) identity *= x;
    return x = identity;
}
template <typename T> constexpr T fpow(T x, long long y, T identity = 1) { return fpow_eq(x, y, identity); }
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
constexpr int M = 998244353;
using mint = modint<M, M - 1>;
mint operator""_m(unsigned long long int x) { return mint(ll(x)); }
const int N = 3000;
int a[N+1];
mint mem[N+1][N+1][2][2];
bool in_mem[N+1][N+1][2][2];
mint count(int n, int i, int s, bool hasL, bool hasR) {
    mint& ans = mem[i][s][hasL][hasR];
    bool& in = in_mem[i][s][hasL][hasR];
    if(not in) {
        if(i == 0) {
            ans = s == 0 and hasL;
        } else {
            ans = count(n, i - 1, s, hasL, hasR)
                + (not hasR and a[i] <= s ? count(n, i - 1, s - a[i], false, true) * (n - i + 1) : 0)
                + (not hasR and a[i] <= s ? count(n, i - 1, s - a[i], true, true) * (n - i + 1) * i : 0)
                + (hasR and not hasL and a[i] <= s ? count(n, i - 1, s - a[i], true, true) * i : 0)
                + (hasR and not hasL and a[i] <= s ? count(n, i - 1, s - a[i], false, true) : 0);
        }
        in = true;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << count(n, n, s, false, false) << endl;
    return 0;
}
