#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;
constexpr int MAX = 200'200;

template<int mod> struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }
    ModInt &operator-=(const ModInt &p) { if((x += mod-p.x) >= mod) x -= mod; return *this; }
    ModInt &operator*=(const ModInt &p) { x = (int)(1LL*x*p.x%mod); return *this; }
    ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) { t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return ModInt(u);
    }
    ModInt pow(int e){
        long long a = 1, p = x;
        while(e > 0) {
            if(e%2 == 0) {p = (p*p) % mod; e /= 2;}
            else {a = (a*p) % mod; e--;}
        }
        return ModInt(a);
    }
    friend ostream &operator<<(ostream &os, const ModInt<mod> &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt<mod> &a) {
        long long x;
        is >> x;
        a = ModInt<mod>(x);
        return (is);
    }
};

template<int mod> struct Combination {
    vector<ModInt<mod>> fact, ifact;
    Combination(int n) : fact(n+1), ifact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i);
        ifact[n] = fact[n].inverse();
        for (int i = n; i > 0; i--) ifact[i-1] = ifact[i] * i;
    }
    ModInt<mod> operator() (int n, int r) {
        if (r < 0 or r > n) return 0;
        return fact[n] * ifact[n-r] * ifact[r];
    }
    const ModInt<mod> &operator[] (int i) const {
        return fact[i];
    }
};

int main() {
    using mint = ModInt<MOD>;
    Combination<MOD> com(MAX);
    
    long long n, m, k;
    cin >> n >> m >> k;
    
    mint ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int d = 1; d < n; d++) {
            mint res = (n - d) * m * m;
            res *= com(n * m - 2, k - 2);
            res *= d;
            ans += res;
        }
        swap(n, m);
    }
    
    cout << ans << '\n';
    return 0;
}