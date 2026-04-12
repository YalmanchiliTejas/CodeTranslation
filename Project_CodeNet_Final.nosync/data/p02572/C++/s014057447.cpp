#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
template <class T> vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
template <typename T> struct edge {
    int to;
    T cost;
    edge(int t, T c) : to(t), cost(c) {}
};
template <typename T> using WGraph = vector<vector<edge<T>>>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

template <uint_fast64_t MOD> class ModInt {
    using u64 = uint_fast64_t;

  public:
    u64 val;

    ModInt(const u64 x = 0) : val((x + MOD) % MOD) {}
    constexpr u64 &value() { return val; }
    constexpr ModInt operator-() { return val ? MOD - val : 0; }
    constexpr ModInt operator+(const ModInt &rhs) const {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt &rhs) const {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt &rhs) const {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt &rhs) const {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt &operator+=(const ModInt &rhs) {
        val += rhs.val;
        if(val >= MOD) {
            val -= MOD;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
        if(val < rhs.val) {
            val += MOD;
        }
        val -= rhs.val;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) {
        val = val * rhs.val % MOD;
        return *this;
    }

    constexpr ModInt &operator/=(const ModInt &rhs) {
        *this *= rhs.inv();
        return *this;
    }

    constexpr bool operator==(const ModInt &rhs) {
        return this->val == rhs.val;
    }
    constexpr bool operator!=(const ModInt &rhs) {
        return this->val != rhs.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) {
        return os << x.val;
    }
    friend constexpr istream &operator>>(istream &is, ModInt<MOD> &x) {
        return is >> x.val;
    }

    constexpr ModInt inv() const { return ModInt(*this).pow(MOD - 2); }

    constexpr ModInt pow(ll e) const {
        u64 x = 1, p = val;
        while(e > 0) {
            if(e % 2 == 0) {
                p = (p * p) % MOD;
                e /= 2;
            } else {
                x = (x * p) % MOD;
                e--;
            }
        }
        return ModInt(x);
    }
};

using mint = ModInt<MOD>;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    mint sum = 0;
    rep(i, N) sum += mint(A[i]);
    mint res = 0;
    rep(i, N) { res += mint(A[i]) * (sum - mint(A[i])); }
    res /= 2;
    cout << res << endl;
}