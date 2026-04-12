#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#ifdef _DEBUG_
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl
#else
#define dump(val)
#endif

using namespace std;

typedef long long int ll;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

template<ll MOD = 1000000007>
class ModInt {
    ll n;
    static ModInt pow(ModInt x, ll p) {
        if (p == 0) {
            return 1;
        } else if (p % 2) {
            return x * pow(x, p - 1);
        } else {
            auto t = ModInt::pow(x, p / 2);
            return t * t;
        }
    }
    ModInt reverse() {
        return ModInt::pow(*this, MOD - 2);
    }

public:
    ModInt()
        : n(0) {}
    ModInt(ll _n)
        : n(_n % MOD) {}
    ModInt operator+=(const ModInt &m) {
        n += m.n;
        if (n >= MOD) {
            n -= MOD;
        }
        return *this;
    }
    ModInt operator-=(const ModInt &m) {
        n -= m.n;
        if (n < 0) {
            n += MOD;
        }
        return *this;
    }
    ModInt operator*=(const ModInt &m) {
        n *= m.n;
        if (n >= MOD) {
            n %= MOD;
        }
        return *this;
    }
    ModInt operator/=(const ModInt &m) {
        return n *= reverse(m);
    }

    ModInt operator+=(const ll l) {
        return (*this) += ModInt(l);
    }
    ModInt operator-=(const ll l) {
        return (*this) -= ModInt(l);
    }
    ModInt operator*=(const ll l) {
        return (*this) *= ModInt(l);
    }
    ModInt operator/=(const ll l) {
        return (*this) /= ModInt(l);
    }
    ModInt operator+(const ModInt &m) {
        auto t = *this;
        return t += m;
    }
    ModInt operator-(const ModInt &m) {
        auto t = *this;
        return t -= m;
    }
    ModInt operator*(const ModInt &m) {
        auto t = *this;
        return t *= m;
    }
    ModInt operator/(const ModInt &m) {
        auto t = *this;
        return t /= m;
    }
    ModInt operator+(const ll l) {
        auto t = *this;
        return t += l;
    }
    ModInt operator-(const ll l) {
        auto t = *this;
        return t -= l;
    }
    ModInt operator*(const ll l) {
        auto t = *this;
        return t *= l;
    }
    ModInt operator/(const ll l) {
        auto t = *this;
        return t /= l;
    }
    ModInt operator=(const ll l) {
        n = l % MOD;
        if (n < 0) {
            n += MOD;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const ModInt &m) {
        out << m.n;
        return out;
    }
    friend istream &operator>>(istream &in, ModInt &m) {
        ll l;
        in >> l;
        m = l;
        return in;
    }
};

using MOD = ModInt<>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string K;
    int D;
    cin >> K >> D;
    int n = K.size();
    auto dp = make_v(n + 1, D, 2, MOD(0));
    dp[0][0][1] = 1;
    REP(i, 0, n) {
        REP(j, 0, D) {
            REP(k, 0, 2) {
                int ub = (k ? K[i] - '0' : 9);
                REP(t, 0, ub + 1) {
                    dp[i + 1][(j + t) % D][k && t == ub] += dp[i][j][k];
                }
            }
        }
    }
    // zero
    cout << dp[n][0][0] + dp[n][0][1] - 1 << endl;
    return 0;
}
