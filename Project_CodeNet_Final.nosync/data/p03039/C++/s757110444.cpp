#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

template <int MOD>
class ModInt {
    using lint = long long;

public:
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // assignment
    ModInt& operator=(const ModInt& x) {
        if (this != &x) { this->val = x.val; }
        return *this;
    }

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt operator~() const { return *this ^ (MOD - 2); }

    // increment / decrement
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) {
        ModInt before = *this;
        ++(*this);
        return before;
    }
    ModInt operator--(int) {
        ModInt before = *this;
        --(*this);
        return before;
    }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator%(const ModInt& x) const { return ModInt(*this) %= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt operator^(const ModInt& x) const { return ModInt(*this) ^= x; }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator%=(const ModInt& x) {
        val %= x.val;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= ~x; }
    ModInt& operator^=(const ModInt& x) {
        int n = x.val;
        ModInt b = *this;
        if (n < 0) n = -n, b = ~b;

        *this = 1;
        while (n > 0) {
            if (n & 1) *this *= b;
            n >>= 1;
            b *= b;
        }
        return *this;
    }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }
    
    // I/O
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
};

using mint = ModInt<1000000007>;

int main(){
    COMinit();
    ll n, m, k;
    cin >> n >> m >> k;

    mint ans = 0;

    mint t = 0;
    for(ll d=1; d<n; d++) t += (d * (n - d));
    t *= m*m;
    ans += t;

    t = 0;
    for(ll d=1; d<m; d++) t += (d * (m - d));
    t *= n*n;
    ans += t;

    cout << ans*COM(n*m-2, k-2) << endl;
}