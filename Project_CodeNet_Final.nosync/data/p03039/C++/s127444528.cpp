#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 200200;
constexpr int MOD = 1000000007;
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
    ModInt inverse() const{
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

struct Combination {
    vector<ModInt<MOD>> fact;
    Combination(int n) : fact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i);
        }
    }
    ModInt<MOD> operator() (int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n]/(fact[n-r]*fact[r]);
    }
};

int main() {
    using mint = ModInt<MOD>;
    Combination com(MAX);
    long long n, m, k;
    cin >> n >> m >> k;
    
    mint ans = 0;
    for (int _ = 0; _ < 2; _++) {
        for (int d = 1; d < n; d++) {
            mint res = ((n - d) * m * m);
            res *= com(n * m - 2, k - 2);
            ans += (res * d);
        }
        swap(n, m);
    }
    
    cout << ans << endl;
    return 0;
}