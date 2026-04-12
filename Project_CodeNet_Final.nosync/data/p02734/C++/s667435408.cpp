#include<iostream>
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

using mint = ModInt<ll, 998244353>;

// 自分の解法
void solve1(int N, int S, vector<ll> A) {
    vector<vector<mint>> dp(N + 1, vector<mint>(3030, 0));  // dp[i][j]: i番目の要素までで和がjとなる部分列の通り数
    rep(i, 1, N + 1) {
        dp[i][A[i - 1]] += i;
        rep(j, 0, 3030) {
            if (j < S) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j - A[i - 1] < 0) {
                continue;
            }
            dp[i][j] += dp[i - 1][j - A[i - 1]];
        }
    }
    mint ans = 0;
    rep(i, 1, N + 1) {
        ans += dp[i][S] * (N - i + 1);
    }
    cout << ans << endl;
}

// writer解
void solve2(int N, int S, vector<ll> A) {
    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(S + 1, vector<mint>(3, 0)));  // dp[i][j][k]: i番目の要素までで和がjでk=0:左端が未定, k=1:左端は決まっているが右端が未定k=2:左右の端が決定している時の通り数
    dp[0][0][0] = 1;
    rep(i, 0, N) rep(j, 0, S + 1) {
        dp[i + 1][j][0] = dp[i][j][0];
        dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
        dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        if (j + A[i] <= S) {
            dp[i + 1][j + A[i]][1] += dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j + A[i]][2] += dp[i][j][0] + dp[i][j][1];
        }
    }
    cout << dp[N][S][2] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    // solve1(N, S, A);
    solve2(N, S, A);
    return 0;
}