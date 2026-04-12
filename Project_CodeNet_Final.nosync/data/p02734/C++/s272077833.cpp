//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//----------------------- Print Function ----------------------//

inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}

//------------------------- Libraries -------------------------//

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = Fp<998244353>;

//--------------------------- Solve ---------------------------//

mint dp[3005][3005][3];

void solve() {
    int N, S; cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            // 左端未選択  (区間がまだはじまってない)
            dp[i+1][j][0] += dp[i][j][0];                           // 左端未選択
            if (j+A[i] <= S) {
                dp[i+1][j+A[i]][1] += dp[i][j][0] * (i+1);          // 左端として選択
                dp[i+1][j+A[i]][2] += dp[i][j][0] * (i+1) * (N-i);  // 左端かつ右端として選択
            }
            

            // 左端選択、右端未選択  (区間の途中)
            dp[i+1][j][1] += dp[i][j][1];                           // 未選択
            if (j+A[i] <= S) {
                dp[i+1][j+A[i]][1] += dp[i][j][1];                  // 選択
                dp[i+1][j+A[i]][2] += dp[i][j][1] * (N-i);          // 右端として選択
            }
            

            // 右端選択済み  (区間が選択済み)
            dp[i+1][j][2] += dp[i][j][2];                           // 未選択
        }
    }

    cout << dp[N][S][2] << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}