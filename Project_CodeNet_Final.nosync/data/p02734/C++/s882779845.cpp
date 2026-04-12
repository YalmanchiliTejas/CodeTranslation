#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

const int MOD = 998244353;
class mint {
    ll x;
public:
    mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
    
    mint operator -() const {
        return mint(-x);
    }
    
    mint &operator +=(const mint &a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint &operator -=(const mint &a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint &operator *=(const mint &a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    mint operator +(const mint &a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator *(const mint &a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator /=(const mint &a) {
        return (*this) *= a.inv();
    }

    mint operator /(const mint &a) const {
        mint res(*this);
        return res /= a;
    }

    friend ostream &operator<<(ostream& os, const mint &m) {
        os << m.x;
        return os;
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, S;
    cin >> N >> S;
    vec A(N);
    Rep (i, N) {
        cin >> A[i];
    }

    vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(S+1, vector<mint>(3, 0)));

    dp[0][0][0] = 1;
    Rep (i, N) {
        Rep (j, S+1) {
            dp[i+1][j][0] += dp[i][j][0];
            if (j+A[i] <= S) dp[i+1][j+A[i]][1] += dp[i][j][0] * (i+1);
            if (j+A[i] <= S) dp[i+1][j+A[i]][2] += dp[i][j][0] * (i+1) * (N-i);

            dp[i+1][j][1] += dp[i][j][1];
            if (j+A[i] <= S) dp[i+1][j+A[i]][1] += dp[i][j][1];
            if (j+A[i] <= S) dp[i+1][j+A[i]][2] += dp[i][j][1] * (N-i);

            dp[i+1][j][2] += dp[i][j][2];
        }
    }

    cout << dp[N][S][2] << "\n";

    // vector<vector<mint>> dp(N+1, vector<mint>(S+1, 0));
    // dp[0][0] = 1;
    // Rep (i, N) {
    //     Rep (j, S+1) {
    //         if (j+A[i] <= S) dp[i+1][j+A[i]] += dp[i][j];
    //         dp[i+1][j] += dp[i][j];
    //     }
    //     dp[i+1][0] = i+2;
    // }

    // // Rep (i, N+1) {
    // //     Rep (j, S+1) {
    // //         cout << dp[i][j] << " \n"[j==S];
    // //     }
    // // }

    // mint ans(0);
    // Rep (i, N+1) {
    //     ans += dp[i][S];
    // }

    // cout << ans << "\n";
}