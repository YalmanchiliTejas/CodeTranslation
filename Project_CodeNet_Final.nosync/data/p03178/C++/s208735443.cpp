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
template <typename T> constexpr T fpow_eq(T& x, ll y, T identity = 1) {
    for(; y > 0; x *= x, y >>= 1) {
        if(y & 1) {
            identity *= x;
        }
    }
    return x = identity;
}
template <typename T> constexpr T fpow(T x, ll y, T identity = 1) { return fpow_eq(x, y, identity); }
#ifdef __TOTIENT_INCLUDED_
template <int M, int PHI_M = phi(M)> struct modint {
#else
template <int M, int PHI_M> struct modint {
#endif
    static constexpr int MOD = M;
    int val;
    constexpr modint() : val(0) {}
    constexpr modint(int val) : val(val % M) { val += val < 0 ? M : 0; }
    constexpr modint(long long val) : modint(int(val % M)) {}
    constexpr modint(const modint& m) : val(m.val) {}
    constexpr explicit operator int() const { return val; }
    constexpr bool operator==(const modint& y) const { return val == y.val; }
    constexpr bool operator!=(const modint& y) const { return val != y.val; }
    constexpr bool operator< (const modint& y) const { return val <  y.val; }
    constexpr bool operator<=(const modint& y) const { return val <= y.val; }
    constexpr bool operator> (const modint& y) const { return val >  y.val; }
    constexpr bool operator>=(const modint& y) const { return val >= y.val; }
    constexpr modint& operator=(const modint& y) { val = y.val; return *this; }
    constexpr modint& operator+=(const modint& y) { val += y.val; val -= val >= M ? M : 0; return *this; }
    constexpr modint& operator-=(const modint& y) { val -= y.val; val += val <  0 ? M : 0; return *this; }
    constexpr modint& operator*=(const modint& y) { val = ll(val) * y.val % M; return *this; }
    constexpr modint& operator/=(const modint& y) { val = ll(val) * fpow(y, PHI_M - 1).val % M; return *this; }
    constexpr modint& operator^=(ll y) { fpow_eq(*this, y); return *this; }
    constexpr modint operator+(const modint& y) const { return modint(val) += y; }
    constexpr modint operator-(const modint& y) const { return modint(val) -= y; }
    constexpr modint operator*(const modint& y) const { return modint(val) *= y; }
    constexpr modint operator/(const modint& y) const { return modint(val) /= y; }
    constexpr modint operator^(ll y) const { return modint(val) ^= y; }
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string k;
    int d;
    cin >> k >> d;
    for(char& c : k) c -= '0';
    const int N = 10000, D = 100;
    static mint C[N+1][D][2];
    for(int i = k.size(); i >= 0; i--) {
        for(int mod = 0; mod < d; mod++) {
            for(int lim : {true, false}) {
                if(i == k.size()) {
                    C[i][mod][lim] = mod == 0;
                } else {
                    for(int dig = 0; dig <= (lim ? k[i] : 9); dig++) {
                        C[i][mod][lim] += C[i+1][(mod + dig) % d][lim and dig == k[i]];
                    }
                }
            }
        }
    }
    cout << C[0][0][true] - 1 << endl;
    return 0;
}
