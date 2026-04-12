#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI acos(-1)
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<typename T> using v1 = vector<T>;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> using v3 = vector<vector<vector<T>>>;
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
const int MOD = 1e9 + 7;
const int INF = numeric_limits<int>::max() - (int)1e8;
const ll INFLL = numeric_limits<ll>::max() - (ll)1e17;

template<int64_t mod>
struct ModInt {
    int64_t value;

    ModInt() : value(0) {}
    ModInt(int64_t x) : value(x >= 0 ? x % mod : (mod - ((-x) % mod) % mod)) {}

    ModInt &operator+=(const ModInt &input) {
        value += input.value;
        if (value >= mod) value -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &input) {
        value += (mod - input.value);
        if (value >= mod) value -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &input) {
        value = value * input.value % mod;
        return *this;
    }

    ModInt &operator/=(const ModInt &input) {
        *this *= input.inverse();
        return *this;
    }

    ModInt inverse() const {
        int64_t base = value, p = mod;
        pair<int64_t, int64_t> save = {1, 0};
        while (p) {
            int64_t temp = base / p;
            swap(base -= temp * p, p);
            swap(save.first -= temp * save.second, save.second);
        }
        return ModInt(save.first);
    }

    ModInt operator-() const { return ModInt(-value); }

    ModInt operator-(const ModInt &input) const { return ModInt(*this) -= input; }

    ModInt operator+(const ModInt &input) const { return ModInt(*this) += input; }

    ModInt operator*(const ModInt &input) const { return ModInt(*this) *= input; }

    ModInt operator/(const ModInt &input) const { return ModInt(*this) /= input; }

    bool operator==(const ModInt &comparsion) const { return value == comparsion.value; }

    bool operator!=(const ModInt &comparsion) const { return value != comparsion.value; }

    friend istream &operator>>(istream &stream, ModInt &input) {
        int64_t temp;
        stream >> temp;
        input = ModInt<mod>(temp);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const ModInt &input) {
        return stream << input.value;
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), x(value);
        while (n > 0) {
            if (n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }

    static const int64_t get_mod() { return mod; }
};

using modint = ModInt<MOD>;

int main() {
    string N;
    int D;
    cin >> N >> D;
    // reverse(N.begin(), N.end());
    v3<modint> dp(N.length() + 1, v2<modint>(2, v1<modint>(D + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < N.length(); i++) {
        int now = N[i] - '0';
        for (int small = 0; small < 2; small++) {
            if (small == 0) {
                for (int j = 0; j < D; j++) {
                    for (int k = 0; k <= now; k++) {
                        if (k == now) dp[i + 1][0][(j + k) % D] += dp[i][0][j];
                        else dp[i + 1][1][(j + k) % D] += dp[i][0][j];
                    }
                }
            } else {
                for (int j = 0; j < D; j++) {
                    for (int k = 0; k < 10; k++) {
                        dp[i + 1][1][(j + k) % D] += dp[i][1][j];
                    }
                }
            }
        }
    }
    cout << dp[N.length()][1][0] + dp[N.length()][0][0] - 1 << endl;
}