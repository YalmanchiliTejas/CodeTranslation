#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...)name
#define _rep(i,n)repi(i,0,n)
#define repi(i,a,b)for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x)x
#define rep(...)MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c)c.begin(),c.end()
#define write(x)cout<<(x)<<'\n'
using namespace std; typedef long long ll; template<class T>using vv = vector<vector<T>>;
template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T, class U>bool chmax(T& a, U&& b) { return a < b ? a = b, 1 : 0; }
template<class T, class U>bool chmin(T& a, U&& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

struct Combination {
    static ll mpow(ll x, ll n) { ll y = 1; for (; n > 0; n /= 2) { y = n % 2 ? y * x % MOD : y; x = x * x % MOD; } return y; }
    vector<ll> fact, ifact;
    Combination(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1; for (int i = 0; i < n; ++i) fact[i + 1] = fact[i] * (i + 1) % MOD;
        ifact[n] = mpow(fact[n], MOD - 2); for (int i = n; i > 0; --i) ifact[i - 1] = ifact[i] * i % MOD;
    }
    ll operator ()(int n, int k) { return k < 0 || k > n ? 0 : fact[n] * ifact[n - k] % MOD * ifact[k] % MOD; }
} Combi(2047);

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    vv<ll> dp = vvec(B - A + 2, N + 1, 0LL);
    dp[0][0] = 1;
    rep(i, B - A + 1) {
        rep(j, N + 1) {
            if (dp[i][j] == 0) continue;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;

            ll rest = N - j;
            ll ifp = 1;
            rep(k, C) ifp = ifp * Combi.ifact[A + i] % MOD;
            rep(k, C, D + 1) {
                ll add = (A + i) * k;
                if (add > rest) break;

                ll a = Combi(rest, add) * Combi.fact[add] % MOD * ifp % MOD * Combi.ifact[k] % MOD;
                dp[i + 1][j + add] = (dp[i + 1][j + add] + a * dp[i][j]) % MOD;

                ifp = ifp * Combi.ifact[A + i] % MOD;
            }
        }
    }

    write(dp[B - A + 1][N]);
}