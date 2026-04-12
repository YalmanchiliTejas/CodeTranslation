#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define int long long

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define DEBUG(x) cout << #x << ": " << (x) << endl
#define DEBUGA(a) cout << #a << ": "; for (const auto& v: (a)) cout << v << endl

// 階乗, 逆元テーブル(mod)
const int nMax = 200005;
ll fact[nMax], fact_inv[nMax], inv[nMax];
ll calc_fact() {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < nMax; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}

// 組合せ, 二項係数
ll mod_comb(ll n, ll r) {
    if (r < 0 || n < r) return 0;
    return ((fact[n] * fact_inv[r]) % MOD) * fact_inv[n - r] % MOD;
}

signed main() {
    int N, M, K;
    cin >> N >> M >> K;

    calc_fact();

    ll sumx = 0, sumy = 0;
    ll comb = mod_comb(N * M - 2, K - 2);

    REP(i, N) sumx = (sumx + i * (N - i) % MOD) % MOD;
    sumx = sumx * M * M % MOD;
    REP(j, M) sumy = (sumy + j * (M - j) % MOD) % MOD;
    sumy = sumy * N * N % MOD;

    ll ans = comb * (sumx + sumy) % MOD;
    cout << ans << endl;

    return 0;
}
