#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;

template<typename T, long long MOD_VALUE>
class ModInt {
    static constexpr long long MOD = MOD_VALUE;
    private:
        T value_;
    public:
        ModInt() {}
        ModInt(const T& value):value_(value % MOD) {}
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

mint dp[10101][2][101];  // dp[i][j][k]: 上位i桁までで(j?K未満:以上)でDのあまりがkとなる通り数

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string K;
    int D;
    cin >> K >> D;
    int N = (int)K.size();
    dp[0][0][0] = 1;
    rep(i, 0, N) rep(j, 0, 2) rep(k, 0, D) {
        int val = (int)(K[i] - '0');
        rep(l, 0, (j ? 9 : val) + 1) {
            // l: i+1桁目の値
            dp[i + 1][l < val || j][(k + l) % D] += dp[i][j][k];
        }
    }
    cout << dp[N][0][0] + dp[N][1][0] - 1 << endl;
    return 0;
}