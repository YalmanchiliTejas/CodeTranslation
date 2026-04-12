#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

template<ll MOD> struct ModInt {
    ll value;
    ModInt() : value(0) {}
    ModInt(const long long& v) : value(v % MOD) {
        while ( value < 0 ) value += MOD;
    }

    ModInt<MOD> operator=(const ModInt& o) {
        value = o.value;
        return *this;
    }
    ModInt<MOD> operator+=(const ModInt& o) {
        value += o.value;
        if ( value >= MOD ) value -= MOD;
        return *this;
    }
    ModInt<MOD> operator-=(const ModInt& o) {
        value += MOD - o.value;
        if (value >= MOD ) value -= MOD;
        return *this;
    }
    ModInt<MOD> operator*=(const ModInt& o) {
        value *= o.value;
        value %= MOD;
        return *this;
    }
    ModInt<MOD> operator/=(const ModInt& o) {
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
        ModInt<MOD> r = 1;
        ModInt<MOD> t = *this;
        while ( n > 0 ) {
            if ( n & 1 ) {
                r *= t;
            }
            t *= t;
            n >>= 1;
        }
        return r;
    }

private:
    long long gcd(long long a, long long b) {
        long long t;
        if ( a < 0 ) a = -a;
        if ( b < 0 ) b = -b;
        while ( b != 0 ) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long long inverse(long long a) {
        long long b = MOD, x = 1, y = 0, s, t;
        while ( b != 0 ) {
            s = y;
            y = x - ( a / b ) * y;
            x = s;
            t = b;
            b = a % b;
            a = t;
        }
        long long r = x % MOD;
        if ( r < 0 ) r += MOD;
        return r;
    }
};

template<ll MOD> std::ostream& operator<< (std::ostream& os, const ModInt<MOD>& o) {
    os << o.value;
    return os;
}

//---------------------------

template<typename T> struct Combination {

    ll size;
    vector<T> fac, finv, inv;
    
    Combination(ll size) {
        fac.assign(size, 0);
        finv.assign(size, 0);
        inv.assign(size, 0);

        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < size; i++){
            fac[i] = fac[i - 1] * i;
            inv[i] = - inv[MOD%i] * (MOD / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }

    // 二項係数
    T C(ll n, ll k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * finv[k] * finv[n - k];
    }

    T P(ll n, ll k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * finv[n - k];
    }

};


//---------------------------
using MInt = ModInt<MOD>;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    Combination<MInt> cb(200010);
    MInt nx = (N+1)*N*(N-1)/6, ny = (M+1)*M*(M-1)/6;
    nx *=  MInt(M).pow(2);
    ny *=  MInt(N).pow(2);
    MInt m = cb.C(N * M - 2, K - 2);
    nx *= m;
    ny *= m;
    
    MInt ans = nx + ny;
    cout << ans << "\n";
    return 0;
}