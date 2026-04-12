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

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

constexpr int MOD = 1000000007;

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
constexpr int FAC_MAX = 200001;
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

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    com_init();
    int n, m, k, x;
    cin >> n >> m >> k;
    x = n * m;
    int sum = 0, s = 0, t = 0;
    rep (i, n) {
        int a = com_mod(n - i, 2), b = com_mod(i + 1, 2);
        eprintf("%d %d\n", a, b);
        s = mod(s + mul_mod(mul_mod(m, m), mod(a + b)));
    }
    rep (i, m) {
        int a = com_mod(m - i, 2), b = com_mod(i + 1, 2);
        eprintf("%d %d\n", a, b);
        t = mod(t + mul_mod(mul_mod(n, n), mod(a + b)));
    }
    sum = div_mod(mod(s + t), 2);
    eprintf("%d %d %d\n", s, t, sum);
    eprintf("%lld*%lld/%lld\n", com_mod(k, 2), com_mod(x, k), com_mod(x, 2));
    cout << div_mod(mul_mod(sum, mul_mod(com_mod(k, 2), com_mod(x, k))), com_mod(x, 2)) << "\n";
    return 0;
}