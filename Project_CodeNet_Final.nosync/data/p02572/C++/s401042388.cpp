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
using Int = ModInt<MOD>;


ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) cin >> A[i];
    Int s = 0, s2 = 0;
    for ( int i = 0; i < N; i++ ) {
        s += A[i];
        s2 += Int(A[i])*Int(A[i]);
    }
    Int t = s*s;
    t -= s2;
    t /= 2;
    ll ans = t.value;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}