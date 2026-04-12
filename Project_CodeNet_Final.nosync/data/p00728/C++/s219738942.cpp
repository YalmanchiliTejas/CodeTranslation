#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;

namespace Math {
    ll modpow(ll b, ll p, ll m) {
        ll r = 1;
        for (; p; p >>= 1, b = b * b % m)
            if (p & 1)
                r = r * b % m;
        return r;
    }

    ll modinv(ll b, ll m) { return modpow(b, m - 2, m); }

    // Least significant bit.
    ll lsb(ll x) { return x & (-x); }

    template <class T> const T inf() { return 0; }
    template <> const ll inf<ll>() { return 0x3f3f3f3f3f3f3f3fll; }
    template <> const int inf<int>() { return 0x3f3f3f3f; }

    template <class T> T gcd(T a, T b) { return abs(__gcd(a, b)); }
    template <class T> T clamp(T n, T l, T r) { return n < l ? l : n > r ? r : n; }
    template <class T> T lcm(T a, T b) { return abs(a / gcd(a, b) * b); }
    template <class T> T sgn(T n) { return n == 0 ? 0 : n > 0 ? 1 : -1; }

    // Generic modular integer.
    template<int MOD, typename IntType = int>
    struct GModint {
        IntType val;

        GModint() : val(0) {}

        GModint(int v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }

        GModint(ll v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }

        explicit operator bool() const { return val != 0; }

        const bool operator==(const GModint &g) const { return val == g.val; }

        const bool operator!=(const GModint &g) const { return val != g.val; }

        const GModint operator+=(const GModint &g) { return *this = *this + g; }

        const GModint operator-=(const GModint &g) { return *this = *this - g; }

        const GModint operator*=(const GModint &g) { return *this = *this * g; }

        const GModint operator/=(const GModint &g) { return *this = *this / g; }

        const GModint operator^=(const GModint &g) { return *this = *this ^ g; }

        const GModint operator-() const { return GModint(val == 0 ? 0 : MOD - val, true); }

        const GModint operator+(const GModint &g) const {
            ll newval = val + g.val;
            if (newval >= MOD)
                newval -= MOD;
            return GModint(newval, true);
        }

        const GModint operator-(const GModint &g) const { return *this + (-g); }

        const GModint operator*(const GModint &g) const { return GModint(1ll * val * g.val); }

        const GModint operator/(const GModint &g) const { return *this * g.inv(); }

        template<class T>
        const GModint operator^(const T t) const { return GModint(modpow(val, t, MOD)); }

        const GModint inv() const { return GModint(modinv(val, MOD)); }
    };

    using Modint = GModint<1000000007>;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    do {
        int n; cin >> n;
        if (n == 0) break;

        int vmin, vmax, sum = 0;
        for (int i = 1; i <= n; i++) {
            int t; cin >> t;
            sum += t;
            if (i == 1) vmin = vmax = t;
            else vmin = min(vmin, t), vmax = max(vmax, t);
        }

        cout << (sum - vmin - vmax) / (n - 2) << endl;
    } while (true);
}

