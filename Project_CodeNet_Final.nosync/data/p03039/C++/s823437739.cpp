#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <limits>

using namespace std;

using i64 = long long int;
using u64 = std::uint_fast64_t;
using P = pair<i64, i64>;

struct edge {
    i64 from, to, cost;
    edge(i64 from, i64 to) : from(from), to(to), cost(1) {}
    edge(i64 from, i64 to, i64 cost) : from(from), to(to), cost(cost) {}
};
using Graph = vector<vector<edge>>;

constexpr i64 SINF = std::numeric_limits<i64>::max() / 10;
const i64 MOD = 1000000007;
const i64 dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
//const i64 dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//const i64 dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//const i64 dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e : t) fill_v(e, v);
}

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

template<std::uint_fast64_t mod=1000000007>
class Modint {
    using u64 = std::uint_fast64_t;
public:
    u64 a;
    constexpr Modint(u64 x = 0) {
       a = x % mod;
    }
    constexpr Modint(const Modint& rhs) {
        a = rhs.a;
    }
    constexpr u64 &value() noexcept { 
        return a;
    }
    constexpr const u64 &value() const noexcept { 
        return a;
    }
    constexpr Modint &operator =(const Modint& rhs){
        a = rhs.a;
        return *this;
    }
    constexpr Modint operator +(const Modint &rhs) const noexcept {
        return Modint(*this) += rhs;
    }
    constexpr Modint operator +(const u64& rhs) const noexcept {
        return Modint(*this) += Modint<mod>(rhs);
    }
    constexpr Modint operator -(const Modint& rhs) const noexcept {
        return Modint(*this) -= rhs;
    }
    constexpr Modint operator -(const u64& rhs) const noexcept {
        return Modint(*this) -= Modint<mod>(rhs);
    }
    constexpr Modint operator *(const Modint& rhs) const noexcept {
        return Modint(*this) *= rhs; 
    }
    constexpr Modint operator *(const u64& rhs) const noexcept {
        return Modint(*this) *= Modint<mod>(rhs);
    }
    constexpr Modint operator /(const Modint& rhs) const noexcept {
        return Modint(*this) /= rhs;
    }
    constexpr Modint operator /(const u64& rhs) const noexcept {
        return Modint(*this) /= Modint<mod>(rhs);
    }
    constexpr bool operator ==(const Modint& rhs) const noexcept {
        return a == rhs.a;
    }
    constexpr bool operator !=(const Modint& rhs) const noexcept {
        return a != rhs.a;
    }
    constexpr Modint& operator +=(const Modint& rhs) noexcept {
        a += rhs.a;
        if (a >= mod) a -= mod;
        return *this;
    }
    constexpr Modint& operator -=(const Modint& rhs) noexcept {
        if (a < rhs.a) a += mod;
        a -= rhs.a;
        return *this;
    }
    constexpr Modint& operator *=(const Modint& rhs) noexcept {
        a = a * rhs.a % mod;
        return *this;
    }
    constexpr Modint& operator/=(Modint rhs) noexcept {
        a = (Modint(*this) * rhs.inv()).a;
		return *this;
    }
    constexpr Modint& operator++() noexcept {
        *this += 1;
        return *this;
    }
    constexpr Modint& operator--() noexcept {
        *this -= 1;
        return *this;
    }
    constexpr Modint pow(u64 n) noexcept {
        Modint<mod> r = 1;
        while (n > 0) {
            if(n & 1){
                r *= *this;
            }
            *this *= *this;
            n >>= 1;
        }
        return r;
    }
    constexpr Modint inv() noexcept {
        return Modint(*this).pow(mod - 2);
    }
};

using mint = Modint<>;

istream& operator>>(istream& os, mint& x) {
    u64 a;
    os >> a;
    x = mint(a);
    return os;
}

ostream& operator<<(ostream& os, const mint& m) noexcept {
    return os << m.a;
}

const i64 MAX = 510000;

i64 fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
i64 COM(i64 n, i64 k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

mint s(i64 x) {
    return mint((x * (x + 1) / 2) % MOD);
}

i64 extGCD(i64 a, i64 b, i64 & x, i64 & y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 d = extGCD(b, a % b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline i64 mod(i64 a, i64 m) {
    return (a % m + m) % m;
}


int main() {
    i64 n, m, k;
    cin >> n >> m >> k;
    COMinit();
    mint ans = 0, cnt = 1;
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < m; ++j) {
            mint x = (s(m - j - 1) + s(j)) * n;
            mint y = (s(n - i - 1) + s(i)) * m;
            mint z = mint(COM(n * m - 2, k - 2)) * (x + y);
            ans += z;
        }
    }
    cout << ans * mint(2).inv() << endl;
}