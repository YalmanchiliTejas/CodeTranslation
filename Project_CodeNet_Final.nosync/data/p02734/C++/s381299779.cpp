#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353;
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

int main() {
    using mint = ModInt<MOD>;
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    mint ans = 0;
    mint dp[n+1][s+1]; dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        // 1 つ前の状態を持ってくる
        for (int j = 0; j <= s; j++) {
            dp[i+1][j] += dp[i][j];
        }
        // A_i を左端にした時の状態数
        if (a[i] <= s) {
            dp[i+1][a[i]] += i + 1;
        }
        // A_i を和として追加するときの遷移
        for (int j = 1; j <= s; j++) {
            if (a[i] + j <= s) {
                dp[i+1][j+a[i]] += dp[i][j];
            }
        }
        // A_i 単体で S になるとき(A_i が左端かつ右端になる)
        if (a[i] == s) {
            ans += (i + 1) * (n - i);
        }
        // A_i が右端になるとき
        if (a[i] < s) {
            ans += (dp[i][s - a[i]] * (n - i));
        }
    }
    
    cout << ans << endl;
    return 0;
}