#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
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
using Int = ModInt<MOD>;

ll solve() {
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    Int ans = 0;
    vector<vector<Int>> dp(N+1, vector<Int>(S+1));
    dp[0][0] = 1;
    for ( int i = 1; i <= N; i++ ) {
        dp[i][0] = 1;
        for ( int j = 0; j <= S; j++ ) {
            dp[i][j] += dp[i-1][j];
            ll k = j - A[i-1];
            if ( k >= 0 ) {
                dp[i][j] += dp[i-1][k];
            }
        }
        ans += dp[i][S];
    }
    return ans.value;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}