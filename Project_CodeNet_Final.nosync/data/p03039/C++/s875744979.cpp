#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 1000000007;
constexpr int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;

int modpow(int x, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {  // nが奇数のとき
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 510000;

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


signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

    COMinit();

    int H, W, K;
    cin >> H >> W >> K;
    int ans = 0;
    rep(i,H){
        ans += COM(H*W-2, K-2) * i * (H-i) * W * W;
        ans %= MOD;
    }
    rep(i,W){
        ans += COM(H*W-2, K-2) * i * (W-i) * H * H;
        ans %= MOD;
    }
    cout << ans << endl;
}