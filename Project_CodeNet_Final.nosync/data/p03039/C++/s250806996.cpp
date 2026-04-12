#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int mod = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
#define ceil(a, b) a / b + !!(a % b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


ll calc(int n, int m, int k) {
    ll sigma_ij = 0;
    rep(d, n) {sigma_ij += (ll)d * (n - d) * (m * m); sigma_ij %= mod;}
    return sigma_ij % mod;
}

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    ll ansx = calc(n, m, k), ansy = calc(m, n, k);
    ll ans = ansx + ansy;
    
    COMinit();
    (ans *= COM(n * m - 2, k - 2)) %= mod;
    cout << ans << endl;
}

