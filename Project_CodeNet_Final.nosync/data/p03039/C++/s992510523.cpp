#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
template <class T> void corner(bool flg, T hoge) {
    if(flg) {
        cout << hoge << endl;
        exit(0);
    }
}
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans = 0;
#include <cstdint>

template <std::uint_fast64_t Modulus> class modint {
    using u64 = std::uint_fast64_t;

  public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if(a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if(a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while(exp) {
            if(exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};

using mint = modint<MOD>;
int main() {
    cin >> n >> m >> k;
    vl v1, v2, v(200100, 0);
    vector<mint> kaijo(n * m + 1);

    kaijo[0] = 1;
    rep(i, n * m) { kaijo[i + 1] = kaijo[i] * (i + 1); }
    rep(i, n) { v1.push_back(n - i); }
    rep(j, m) { v2.push_back(m - j); }

    rep(i, n) {
        rep(j, m) {
            if(i * j == 0) {
                v[i + j] += v1[i] * v2[j];
            } else {
                v[i + j] += v1[i] * v2[j] * 2;
            }
            v[i+j]%=MOD;
        }
    }

    mint ans=0,x;
    x=kaijo[n*m-2]/(kaijo[n*m-k]*kaijo[k-2]);
    rep(i,m+n){
        ans+=x*(v[i]*i);
    }

    cout << ans.a << endl;
}