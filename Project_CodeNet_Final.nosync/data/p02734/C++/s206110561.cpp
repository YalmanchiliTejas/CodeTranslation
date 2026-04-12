#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

constexpr int MOD = 998244353;

// + - * / ^
int mod(int a)
{
    int res = a % MOD;
    if(res < 0) {
        return res + MOD;
    }
    return res;
}
int mul_mod(int a, int b)
{
    ll res = ((ll)a * (ll)b) % MOD;
    return mod((int)res);
}
int pow_mod(int a, int b)
{
    ll res = 1;
    while (b > 0) {
        if(b & 1) {
            res = res * (ll)a % (ll)MOD;
        }
        a = mul_mod(a, a);
        b >>= 1;
    }
    return (int)res;
}
int inv_mod(int a)
{
    return pow_mod(a, MOD - 2);
}
int div_mod(int a, int b)
{
    return mul_mod(a, inv_mod(b));
}

// ! C
constexpr int FAC_MAX = 3000001;
ll fac[FAC_MAX], finv[FAC_MAX], inv[FAC_MAX];
void com_init()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < FAC_MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll com_mod(int a, int b){
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}


int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, s; cin >> n >> s;
    vector<int> a(n); rep (i, n) cin >> a[i];
    vector<vector<ll> > dp(n + 1, vector<ll> (7000));
    rep (i, n + 1) dp[i][0] = i + 1;
    rep (i, n) {
        rep (j, s + 1) {
            if (j > 0) dp[i + 1][j] = mod(dp[i + 1][j] + dp[i][j]);
            dp[i + 1][j + a[i]] = mod(dp[i + 1][j + a[i]] + dp[i][j]);
        }
    }
    rep (j, s + 1) {
        rep (i, n + 1) {
            eprintf("%4lld", dp[i][j]);
        }
        eprintf("\n");
    }
    ll ans = 0;
    rep (i, n + 1) {
        ans = mod(ans + dp[i][s]);
    }
    eprintf("%lld %lld\n", dp[n][s], ans);
    cout << ans << "\n";
    return 0;
}