#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using u64 = uint_fast64_t;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return true;} return false; }
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return true;} return false; }
inline int popcount(int x) {return __builtin_popcount(x);}
inline int popcount(long long x) {return __builtin_popcountll(x);}
void print() { cout << "\n"; }
template<class T, class... Args>
void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <uint_fast64_t Modulus> 
struct ModInt {
    using u64 = uint_fast64_t;

    u64 a;

    constexpr ModInt(const long long x = 0) noexcept : a(x >= 0 ? x % Modulus : (Modulus - (-x) % Modulus) % Modulus) {}
    constexpr u64 &value() noexcept {return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr ModInt operator+(const ModInt rhs) const noexcept {return ModInt(*this) += rhs;}
    constexpr ModInt operator-(const ModInt rhs) const noexcept {return ModInt(*this) -= rhs;}
    constexpr ModInt operator*(const ModInt rhs) const noexcept {return ModInt(*this) *= rhs;}
    constexpr ModInt operator/(const ModInt rhs) const noexcept {return ModInt(*this) /= rhs;}
    constexpr ModInt operator^(const long long rhs) const noexcept {return ModInt(*this) ^= rhs;}
    constexpr bool operator==(const ModInt &rhs) const noexcept {return a == rhs.a;}
    constexpr bool operator!=(const ModInt &rhs) const noexcept {return a != rhs.a;}
    constexpr ModInt &operator+=(const ModInt rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }
    constexpr ModInt &operator^=(long long exp) noexcept {
        ModInt rhs = a;
        a = 1;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }

    friend ostream &operator<<(ostream& os, const ModInt& rhs) noexcept {return os << rhs.a;}
    friend istream &operator>>(istream& is, ModInt& rhs) noexcept {long long a; is >> a; rhs = a; return is;}
};

using mint = ModInt<MOD>;


template<typename T>
struct Compress {
    vector<T> xs;

    Compress(){};
    Compress(const vector<T> &vs) {add(vs);}
    Compress(const initializer_list<vector<T>> &vs) {for(auto &p : vs) add(p);}

    void add(const vector<T> &vs) {copy(begin(vs), end(vs), back_inserter(xs));}
    void add(const T &x) {xs.emplace_back(x);}

    int build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
        return (int)xs.size();
    }

    vector<int> get(const vector<T> &vs) const {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
            return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    int get(const T &x) const {return lower_bound(begin(xs), end(xs), x) - begin(xs);}

    const T &operator[](int k) const {return xs[k];}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> h(N+1);
    rep(i,N) cin >> h[i+1];

    Compress<int> Com(h);
    Com.add((int)1e9+1);
    int M = Com.build();
    vector<vector<mint>> dp(N+1, vector<mint>(M));
    dp[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        if (h[i] > h[i-1]) {
            int H = Com.get(h[i-1]) + 1;
            mint C = 2;
            C ^= h[i] - h[i-1];
            rep(j,M) {
                if (Com[j] <= h[i-1]) {
                    dp[i][j] += dp[i-1][j]*C;
                } else if (Com[j] <= h[i]) {
                    mint two = 2;
                    two ^= Com[j] - Com[j-1];
                    if (j==1) two /= 2;
                    dp[i][j] += dp[i-1][H]*(two-1)*(mint(2)^(h[i]-Com[j]))*2;
                } else {
                    dp[i][j] += dp[i-1][H]*2;
                    break;
                }
            }
        } else {
            int H = Com.get(h[i]) + 1;
            rep(j,M) {
                if (Com[j] <= h[i]) {
                    dp[i][j] += dp[i-1][j];
                } else if (Com[j] <= h[i-1]) {
                    dp[i][H] += dp[i-1][j]*2;
                } else {
                    dp[i][H] += dp[i-1][j]*2;
                    break;
                }
            }
        }
    }

    mint ans = 0;
    rep(j,M) ans += dp[N][j];
    cout << ans << ln;
}
