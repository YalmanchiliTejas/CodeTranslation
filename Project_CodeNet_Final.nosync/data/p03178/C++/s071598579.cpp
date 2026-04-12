#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const ll MOD = 1e9 + 7;
template<ll MOD> struct ModInt {
    ll value;
    ModInt() : value(0) {}
    ModInt(const ll& v) : value(v % MOD) {
        if ( value < 0 ) value += MOD;
    }
    ModInt<MOD>& operator=(const ModInt& o) {
        value = o.value;
        return *this;
    }
    inline bool operator==(const ModInt& o) {
        return value == o.value;
    }
    inline bool operator!=(const ModInt& o) {
        return value != o.value;
    }
    ModInt<MOD>& operator+=(const ModInt& o) {
        value += o.value;
        if ( value >= MOD ) value -= MOD;
        return *this;
    }
    ModInt<MOD>& operator-=(const ModInt& o) {
        value += MOD - o.value;
        if (value >= MOD ) value -= MOD;
        return *this;
    }
    ModInt<MOD>& operator*=(const ModInt& o) {
        value *= o.value;
        value %= MOD;
        return *this;
    }
    ModInt<MOD>& operator/=(const ModInt& o) {
        value *= inverse(o.value);
        value %= MOD;
        return *this;
    }
    ModInt<MOD> operator-() {
        return ModInt<MOD>(-value);
    }
    ModInt<MOD> operator+(const ModInt& o) {
        ModInt<MOD> r(*this);
        r += o;
        return r;
    }
    ModInt<MOD> operator-(const ModInt& o) {
        ModInt<MOD> r(*this);
        r -= o;
        return r;
    }
    ModInt<MOD> operator*(const ModInt& o) {
        ModInt<MOD> r(*this);
        r *= o;
        return r;
    }
    ModInt<MOD> operator/(const ModInt& o) {
        ModInt<MOD> r(*this);
        r /= o;
        return r;
    }
    ModInt<MOD> pow(ll n) {
        ModInt<MOD> t(*this), r = 1;
        while ( n > 0 ) {
            if ( n & 1 ) r *= t;
            t *= t;
            n >>= 1;
        }
        return r;
    }
private:
    ll inverse(ll a) {
        ModInt<MOD> t(a);
        return t.pow(MOD - 2).value;
    }
};
template<ll MOD> std::ostream& operator<< (std::ostream& os, const ModInt<MOD>& o) {
    os << o.value;
    return os;
}
template<ll MOD> std::istream& operator>> (std::istream& is, ModInt<MOD>& o) {
    is >> o.value;
    return is;
}

using Int = ModInt<MOD>;

ll solve() {
    string K;
    ll D;
    cin >> K >> D;
    int n = K.size();
    vector<vector<Int>> dp0(n+1, vector<Int>(D)), dp1(n+1, vector<Int>(D));
    dp1[0][0] = 1;
    for ( int i = 1; i <= n; i++ ) {
        int k = K[i-1] - '0';
        for ( int d = 0; d < D; d++ ) {
            for ( int j = 0; j < 10; j++ ) {
                dp0[i][(d+j)%D] += dp0[i-1][d];
            }
            for ( int j = 0; j < k; j++ ) {
                dp0[i][(d+j)%D] += dp1[i-1][d];
            }
            dp1[i][(d+k)%D] += dp1[i-1][d];
        }
    }
    Int ans = dp0[n][0] + dp1[n][0] - Int(1);
    return ans.value;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}