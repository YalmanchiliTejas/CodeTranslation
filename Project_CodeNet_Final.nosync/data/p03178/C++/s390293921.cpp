#include <bits/stdc++.h>
using namespace std;
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
        while(b > 0) { t = a/b; a -= t*b; swap(a, b); u -= t*v; swap(u, v); }
        return ModInt(u);
    }
    ModInt pow(int e){
        long long a = 1, p = x;
        while(e > 0) {
            if (e%2 == 0) { p = (p*p)%mod; e /= 2; }
            else { a = (a*p)%mod; e--; }
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

const int MAX_N = 10010;
const int MAX_D = 110;
const int MOD = 1e9+7;

int main() {
    string S;
    int D;
    cin >> S >> D;
    int N = S.length();
    
    ModInt<MOD> dp[MAX_N][2][MAX_D];
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        const int c = S[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= (j ? 9 : c); k++) {
                for (int d = 0; d < D; d++) {
                    dp[i+1][j || (k < c)][(d + k) % D] += dp[i][j][d];
                }
            }
        }
    }
    
    ModInt<MOD> ans = dp[N][0][0] + dp[N][1][0] - 1;
    cout << ans << endl;
    return 0;
}