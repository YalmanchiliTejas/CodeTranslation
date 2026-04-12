#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const ll MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

const ll MAX = 210000;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() // 二項係数を求める時は前処理としてCOMinit()をする
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k) {
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    COMinit();
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(ll i = 1; i < n; i++) {
        (ans += i * (n - i) % MOD * m % MOD * m % MOD) %= MOD;
    }

    for(ll i = 1; i < m; i++) {
        (ans += i * (m - i) % MOD * n % MOD * n % MOD) %= MOD;
    }

    (ans *= COM(n * m - 2, k - 2)) %= MOD;
    cout << ans << endl;
}