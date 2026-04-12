#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

constexpr int MOD = 1e9 + 7;

template<long long mod>
struct mint {
private:
    long long x;
public:
    mint(long long x = 0) :x((mod + x) % mod) {}
    mint(std::string &s) {
        long long z = 0;
        for (int i = 0; i < s.size(); i++) {
            z *= 10;
            z += s[i] - '0';
            z %= mod;
        }
        this->x = z;
    }
    mint& operator+=(const mint &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint &a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint& operator/=(const mint &a) {
        long long n = mod - 2;
        mint<mod> u = 1, b = a;
        while (n > 0) {
            if (n & 1) {
                u *= b;
            }
            b *= b;
            n >>= 1;
        }
        return *this *= u;
    }
    mint operator+(const mint &a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint &a) const {
        mint res(*this);
        return res *= a;
    }
    mint operator/(const mint &a) const {
        mint res(*this);
        return res /= a;
    }
    friend std::ostream& operator<<(std::ostream &os, const mint &n) {
        return os << n.x;
    }
    bool operator==(const mint &a) const {
        return this->x == a.x;
    }
};

//powMod
ll powMod(ll k, ll n, ll mod) {
    ll x = 1;
    while (n > 0) {
        if (n & 1) {
            x = x * k % mod;
        }
        k = k * k % mod;
        n >>= 1;
    }
    return x;
}

// comb (一つのみ) O(r)
ll comb(ll n, ll r, ll mod) {
    ll ret = 1;
    while (true) {
        if (r == 0) break;
        ll N = n % mod;
        ll R = r % mod;
        if (N < R) return 0;
        for (int i = 0; i < R; i++)
        {
            ret = ret * (N - i) % mod;
        }
        ll imul = 1;
        for (int i = 0; i < R; i++)
        {
            imul = imul * (i + 1) % mod;
        }
        ret = ret * powMod(imul, mod - 2, mod) % mod;
        n /= mod; r /= mod;
    }
    return ret;
}

int main() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    mint<MOD> c = comb((ll)n*m - 2, k - 2, MOD);
    mint<MOD> ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += (mint<MOD>(n - 1 - i)*(m - 1 - j)*(n + m - i - j) / 2 + mint<MOD>(n - 1 - i)*(n - i) / 2 + mint<MOD>(m - 1 - j)*(m - j) / 2 + mint<MOD>(n - 1 - i)*j*(n - i + j + 1) / 2) * c;
        }
    }
    cout << ans << endl;
    return 0;
}