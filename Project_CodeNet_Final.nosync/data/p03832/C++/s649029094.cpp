#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

template <ll mod>
struct modular {
    ll value;
    modular(ll x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }

    modular& operator+=(modular other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(modular other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(modular other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(modular other) {
        ll a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            ll t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        value = value * a % mod;
        if (value < 0) value += mod;
        return *this;
    }
    modular& operator^=(modular other) {
        ll r = 1, x = value, n = other.value;
        while (n > 0) {
            if (n & 1) r = r * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        value = r;
        return *this;
    }
    modular operator+(modular rhs) {
        return modular(*this) += rhs;
    }
    modular operator-(modular rhs) {
        return modular(*this) -= rhs;
    }
    modular operator*(modular rhs) {
        return modular(*this) *= rhs;
    }
    modular operator/(modular rhs) {
        return modular(*this) /= rhs;
    }
    modular operator^(modular rhs) {
        return modular(*this) ^= rhs;
    }
    bool operator==(modular rhs) {
        return value == rhs.value;
    };
    bool operator!=(modular rhs) {
        return value != rhs.value;
    };
    bool operator<(modular rhs) {
        return value < rhs.value;
    }
};
template <ll mod>
string to_string(modular<mod> x) {
    return to_string(x.value);
}
template <ll mod>
ostream& operator<<(ostream& stream, modular<mod> x) {
    return stream << x.value;
}
template <ll mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}
const ll mod = 1e9 + 7;
using mint = modular<mod>;

int n, a, b, c, d;
vector<mint> fac(2000, 1);
vector<vector<mint>> memo(1010, vector<mint>(1010, -1));

inline mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fac[n] / fac[k] / fac[n - k];
}

inline mint calc(int i, int m) {
    if (memo[i][m] != -1) return memo[i][m];
    if (i < c * m) return memo[i][m] = 0;
    mint res, tmp = 1;
    if (m != b) res += calc(i, m + 1);
    int t = i;
    rep(j, 1, c) {
        tmp *= C(t, m);
        tmp /= j;
        t -= m;
    }
    rep(j, c, d + 1) {
        tmp *= C(t, m);
        tmp /= j;
        t -= m;
        if (i < j * m)
            break;
        if (i == j * m) {
            res += tmp;
        } else if (m != b) {
            res += tmp * calc(i - j * m, m + 1);
        }
    }
    // debug(i, m, res);
    return memo[i][m] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b >> c >> d;
    rep(i, 1, 2000) {
        fac[i] = fac[i - 1] * i;
    }
    cout << calc(n, a) << endl;
    return 0;
}