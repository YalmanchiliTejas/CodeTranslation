#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long; 
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
//constexpr long long MOD = 998244353LL;
template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true;} return false; }
template<class T, class U> inline bool chmin(T &a, U b) { if (a > b) { a = b; return true;} return false; }
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <std::uint_fast64_t Modulus> 
struct ModInt {
    using u64 = std::uint_fast64_t;

    u64 a;

    constexpr ModInt(const long long x = 0) noexcept : a(x >= 0 ? x % Modulus : (Modulus - (-x) % Modulus) % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr ModInt operator+(const ModInt rhs) const noexcept {return ModInt(*this) += rhs;}
    constexpr ModInt operator-(const ModInt rhs) const noexcept {return ModInt(*this) -= rhs;}
    constexpr ModInt operator*(const ModInt rhs) const noexcept {return ModInt(*this) *= rhs;}
    constexpr ModInt operator/(const ModInt rhs) const noexcept {return ModInt(*this) /= rhs;}
    constexpr ModInt operator^(const long long rhs) const noexcept {return ModInt(*this) ^= rhs;}
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

    bool operator==(const ModInt &p) const {return a == p.a;}
    bool operator!=(const ModInt &p) const {return a != p.a;}

};

using mint = ModInt<MOD>;


struct ModCombination {
    vector<mint> Fac;
    vector<mint> Facinv;

    ModCombination(int x) {
        Fac.resize(x+1);
        Facinv.resize(x+1);
        Fac[0] = 1;
        for (int i = 0; i < x; ++i) Fac[i+1] = Fac[i]*(i+1);
        Facinv[x] = Fac[0]/Fac[x];
        for (int i = x; i > 0; --i) Facinv[i-1] = Facinv[i]*i;
    }

    mint get(int n, int k) {
        if (k < 0 || k > n) return 0;
        return Fac[n]*Facinv[k]*Facinv[n-k];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N,A,B,C,D; cin >> N >> A >> B >> C >> D;

    ModCombination MC(N);
    auto calc=[&](int x, int y) {
        mint a = MC.Facinv[x];
        a ^= y;
        a *= MC.Facinv[y];
        return a;
    };

    vector<vector<mint>> mat(N+1, vector<mint>(N+1));
    rep(i,N+1) {
        rep(j,N+1) {
            mat[i][j] = calc(i,j);
        }
    }
    vector<vector<mint>> dp(B-A+2, vector<mint>(N+1));
    dp[0][0] = 1;
    rep(i,B-A+1) {
        int AA = A+i;
        rep(j,N+1) {
            dp[i+1][j] += dp[i][j];
            for (int k = C; k <= D; k++) {
                if (j+AA*k > N) break;
                dp[i+1][j+AA*k] += dp[i][j]*mat[AA][k];
            }
        }
    }
    dp[B-A+1][N] *= MC.Fac[N];

    cout << dp[B-A+1][N].a << ln;
}