#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


// modint
// 1000000007 で割ったあまりに関する四則演算を直感的に行える
struct Fp {
    static int &mod() {
        static int mod_;
        return mod_;
    }
    static void setmod(const int x) { mod() = x; }
    static int getmod() { return mod(); }
    
    long long val;
    Fp(long long v = 0) noexcept : val(v % mod()) {
        if (val < 0) v += mod();
    }
    Fp operator - () const {
        return val ? mod() - val : 0;
    }
    Fp operator + (const Fp& r) const { return Fp(*this) += r; }
    Fp operator - (const Fp& r) const { return Fp(*this) -= r; }
    Fp operator * (const Fp& r) const { return Fp(*this) *= r; }
    Fp operator / (const Fp& r) const { return Fp(*this) /= r; }
    Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= mod()) val -= mod();
        return *this;
    }
    Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += mod();
        return *this;
    }
    Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % mod();
        return *this;
    }
    Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = mod(), u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % mod();
        if (val < 0) val += mod();
        return *this;
    }
    bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
};

ostream& operator << (ostream &os, const Fp& x) noexcept {
    return os << x.val;
}
istream& operator >> (istream &is, Fp& x) noexcept {
    return is >> x.val;
}

Fp modpow(const Fp &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
}


// 二項係数ライブラリ
template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[Fp::getmod()%i] * (Fp::getmod()/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};


// スターリング数 (n 個を k グループにわける、n >= k)
template<class T> struct Stirling {
    vector<vector<T> > S;
    constexpr Stirling(int MAX) noexcept : S(MAX, vector<T>(MAX, 0)) {
        S[0][0] = 1;
        for (int n = 1; n < MAX; ++n) {
            for (int k = 1; k <= n; ++k) {
                S[n][k] = S[n-1][k-1] + S[n-1][k] * k;
            }
        }
    }
    constexpr T get(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return S[n][k];
    }
};



const int MAX = 3100;
int main() {
    // 入力
    long long N, MOD = 1000000007;
    cin >> N >> MOD;
    Fp::setmod(MOD);
    using mint = Fp;
    
    // 前計算
    BiCoef<mint> bc(MAX); // 二項係数計算の前処理
    Stirling<mint> sl(MAX); // スターリング数の前処理

    // 2^2^n の前計算 (2^2^(n+1) = (2^2^n)^2
    vector<mint> dtwo(MAX, 0);
    dtwo[0] = 2;
    for (int i = 1; i < MAX; ++i) dtwo[i] = dtwo[i-1] * dtwo[i-1];
    
    // 求める
    mint res = 0;
    for (int n = 0; n <= N; ++n) {
        mint add = 0;
        for (int k = 0; k <= n; ++k) {
            mint jiyudo = modpow(mint(2), (N-n)*k) * dtwo[N-n];
            mint core = sl.get(n, k) + sl.get(n, k+1) * (k+1);
            add += core * jiyudo;
        }
        mint choose = bc.com(N, n);
        add *= choose;
        if (n % 2 == 0) res += add;
        else res -= add;
    }
    cout << res << endl;
}
