#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define rrep(i, n) for (int i = (int)n-1; i >= 0; --i)
using namespace std;
using ll = long long;

template<typename T>
inline bool chmax(T& a, const T& b) {
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
inline bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

/**
 * @brief 多次元 vector の作成
 * @author えびちゃん
 */
namespace detail {
    template<typename T, int N>
    auto make_vec(vector<int>& sizes, T const& x) {
        if constexpr (N == 1) {
            return vector(sizes[0], x);
        } else {
            int size = sizes[N-1];
            sizes.pop_back();
            return vector(size, make_vec<T, N-1>(sizes, x));
        }
    }
}
template<typename T, int N>
auto make_vec(int const(&sizes)[N], T const& x = T()) {
    vector<int> s(N);
    for (int i = 0; i < N; ++i) s[i] = sizes[N-i-1];
    return detail::make_vec<T, N>(s, x);
}

__attribute__((constructor))
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

template<uint_fast64_t Modulus>
struct modint {
    using u64 = uint_fast64_t;
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64& value() noexcept { return a; }
    constexpr const u64& value() const noexcept { return a; }
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
    constexpr modint& operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) a -= Modulus;
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) noexcept {
        if (a < rhs.a) a += Modulus;
        a -= rhs.a;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) noexcept {
        return *this *= rhs.inv();
    }
    constexpr modint& operator++() noexcept {
        a++;
        if (a == Modulus) a = 0;
        return *this;
    }
    constexpr modint operator++(int) noexcept {
        modint tmp(*this);
        operator++();
        return tmp;
    }
    constexpr modint& operator--() noexcept {
        if (a == 0) a = Modulus;
        a--;
        return *this;
    }
    constexpr modint operator--(int) noexcept {
        modint tmp(*this);
        operator--();
        return tmp;
    }
    constexpr modint pow(u64 exp) const noexcept {
        modint res(1), mul(*this);
        for (; exp; mul *= mul, exp >>= 1) if (exp & 1) res *= mul;
        return res;
    }
    constexpr modint inv() const noexcept {
        return modint(*this).pow(Modulus - 2);
    }
    constexpr bool operator==(modint rhs) const noexcept { return a == rhs.a; }
    constexpr bool operator!=(modint rhs) const noexcept { return a != rhs.a; }
    friend ostream& operator<<(ostream& os, const modint<Modulus>& rhs) { return os << rhs.a; }
};

using mint = modint<1000000007>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep(i, n) sum += a[i];

    mint ans = 0;
    rep(i, n) {
        ans += mint(sum - a[i]) * a[i];
    }
    ans /= 2;
    cout << ans << '\n';
}
