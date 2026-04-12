#include <bits/stdc++.h>
using namespace std;
//#define int long long
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }
const int MAX_D = 10100;
const int MAX_K = 100;
const int MOD = 1e9+7;

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

using mint = ModInt<MOD>;

int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.length();
    
    mint dp[MAX_D][2][MAX_K] = {0};
    dp[0][0][0] = 1;
    
    for (int i = 0; i < N; i++) {
        const int D = S[i] - '0';
        for (int flag = 0; flag < 2; flag++) {
            for (int k = 0; k < MAX_K; k++) {
                for (int d = 0; d <= (flag ? 9 : D); d++) {
                    dp[i+1][flag || (d<D)][(k+d)%K] += dp[i][flag][k];
                }
            }
        }
    }
    
    cout << (dp[N][0][0] + dp[N][1][0])-1 << endl;
    return 0;
}