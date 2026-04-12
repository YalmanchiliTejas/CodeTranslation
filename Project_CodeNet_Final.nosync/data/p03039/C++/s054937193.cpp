#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

/* ------------- ANSWER ------------- */
/* ---------------------------------- */


const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {

    ll n, m, k;
    cin >> n >> m >> k;
    COMinit();

    // sum for x
    ll sum_x = 0;
    rep(i, m) sum_x += i * (m - i) * n * n;
    sum_x %= mod;
    sum_x *= COM(n * m - 2, k - 2);
    sum_x %= mod;

    // sum for y
    ll sum_y = 0;
    rep(i, n) sum_y += i * (n - i) * m * m;
    sum_y %= mod;
    sum_y *= COM(n * m - 2, k - 2);
    sum_y %= mod;

    cout << (sum_y + sum_x) % mod << endl;
    return 0;
}