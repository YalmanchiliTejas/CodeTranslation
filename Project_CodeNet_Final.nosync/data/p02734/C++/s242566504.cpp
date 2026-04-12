#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
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
        a %= mod;
        if (a < 0) a += mod;
        value = value * a % mod;
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
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream << x.value;
}
template <ll mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}
const ll mod = 998244353;
using mint = modular<mod>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<mint> dp(s + 1);
    dp[0] = 1;
    mint ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= s) {
            ans += dp[s - a[i]] * (mint)(i + 1);
        }
        for (int j = s; j > 0; j--) {
            if (j + a[i] < s) dp[j + a[i]] += dp[j];
        }
        if (a[i] < s) {
            dp[a[i]] += mint(n - i);
        }
        dp[0] += 1;
    }
    cout << ans << endl;
    return 0;
}