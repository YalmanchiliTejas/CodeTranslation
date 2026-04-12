#include <iostream>
#include <string>
using namespace std;

template <int M> class ModInt {
    int x;

  public:
    constexpr ModInt() : x(0) {}
    constexpr ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}
    constexpr ModInt &operator+=(const ModInt p) {
        if((x += p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt p) {
        if((x += M - p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt p) {
        x = (int)(1LL * x * p.x % M);
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt p) {
        *this *= p.inverse();
        return *this;
    }
    constexpr ModInt operator-() const { return ModInt(-x); }
    constexpr ModInt operator+(const ModInt p) const {
        return ModInt(*this) += p;
    }
    constexpr ModInt operator-(const ModInt p) const {
        return ModInt(*this) -= p;
    }
    constexpr ModInt operator*(const ModInt p) const {
        return ModInt(*this) *= p;
    }
    constexpr ModInt operator/(const ModInt p) const {
        return ModInt(*this) /= p;
    }
    constexpr bool operator==(const ModInt p) const { return x == p.x; }
    constexpr bool operator!=(const ModInt p) const { return x != p.x; }
    constexpr ModInt inverse() const {
        int a = x, b = M, u = 1, v = 0, t = 0;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    constexpr ModInt pow(int64_t k) const {
        ModInt ret(1), mul(x);
        while(k > 0) {
            if(k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    constexpr friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    constexpr friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t = 0;
        is >> t;
        a = ModInt(t);
        return (is);
    }
};
using mint = ModInt<1000000007>;

int N, D;

int K[10009];

mint dp[10009][2][109];

int main() {
    string s;
    cin >> s;
    N = s.size();
    for(int i = 0; i < N; i++)
        K[i] = s[i] - '0';

    cin >> D;

    dp[0][1][0] = 1;

    for(int i = 0; i < N; i++) {
        for(int d = 0; d < D; d++) {
            // 0 -> 0
            for(int k = 0; k < 10; k++)
                dp[i + 1][0][(d + k) % D] += dp[i][0][d];
            // 1 -> 0
            for(int k = 0; k < K[i]; k++)
                dp[i + 1][0][(d + k) % D] += dp[i][1][d];
            // 1 -> 1
            dp[i + 1][1][(d + K[i]) % D] += dp[i][1][d];
        }
    }

    cout << dp[N][0][0] + dp[N][1][0] - 1 << endl;

    return 0;
}