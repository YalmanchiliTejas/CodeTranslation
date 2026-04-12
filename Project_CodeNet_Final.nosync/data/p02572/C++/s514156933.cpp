#include<iostream>
#include<numeric>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

template<typename T, long long MOD_VALUE>
class ModInt {
    static constexpr long long MOD = MOD_VALUE;
private:
    T value_;
public:
    ModInt() {}
    ModInt(const T& value) {if (value >= 0) {value_ = value % MOD;} else {T k = (MOD - 1 - value) / MOD; value_ = (value + k * MOD) % MOD;}}
    ModInt& operator+=(const ModInt& x)  {value_ += x.value_; if (value_ >= MOD) value_ -= MOD; return *this;}
    friend ModInt& operator+=(const T& x, const ModInt& y) {ModInt res(x); res.value_ += x.value_; if (res.value_ >= MOD) res.value_ -= MOD; return res;}
    ModInt& operator-=(const ModInt& x) {if (value_ < x.value_) value_ += MOD; value_ -= x.value_; return *this;}
    friend ModInt& operator-=(const T& x, const ModInt& y) {ModInt res(x); if (res.value_ < y.value_) res.value_ += MOD; res.value_ -= y.value_; return res;}
    ModInt& operator*=(const ModInt& x) {value_ = (value_ * x.value_) % MOD; return *this;}
    friend ModInt& operator*=(const T& x, const ModInt& y) {ModInt res(x); res.value_ = (res.value_ * y.value_) % MOD; return res;}
    const ModInt operator+(const ModInt& x) const {return ModInt(*this) += x;}
    friend const ModInt operator+(const T& x, const ModInt& y) {return ModInt(x) += y;}
    const ModInt operator-(const ModInt& x) const {return ModInt(*this) -= x;}
    friend const ModInt operator-(const T& x, const ModInt& y) {return ModInt(x) -= y;}
    const ModInt operator*(const ModInt& x) const {return ModInt(*this) *= x;}
    friend const ModInt operator*(const T& x, const ModInt& y) {return ModInt(x) *= y;}
    static ModInt modpow(ModInt x, long long y) {ModInt z = 1; while (y > 0) {if (y & 1) {z *= x;}x *= x; y /= 2;} return z;}
    ModInt& operator/=(const ModInt& x) {return *this *= modpow(x, MOD - 2);}
    const ModInt operator/(const ModInt& x) const {return ModInt(*this) /= x;}
    friend const ModInt operator/(const T& x, const ModInt& y) {return ModInt(x) /= y;}
    ModInt operator++(int) {ModInt tmp(*this); value_ = (value_ + 1 == MOD ? 0 : value_ + 1); return tmp;}
    ModInt operator--(int) {ModInt tmp(*this); value_ = (value_ - 1 < 0 ? MOD - 1 : value_ - 1); return tmp;}
    friend istream& operator>>(istream& stream, ModInt& x) {stream >> x.value_; x.value_ %= MOD; return stream;}
    friend ostream& operator<<(ostream& stream, const ModInt& x) {stream << x.value_; return stream;}
};

using mint = ModInt<ll, 1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    ll sum = accumulate(all(A), 0LL);
    mint ans = 0;
    rep(i, 0, N) {
        sum -= A[i];
        ans += mint(A[i]) * mint(sum);
    }
    cout << ans << endl;
    return 0;
}