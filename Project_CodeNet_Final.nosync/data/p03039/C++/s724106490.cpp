#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

const int MAX = 2e5+5;
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

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    COMinit();
    ll N,M,K;
    cin >> N >> M >> K;
    ll ans = 0 , sum = 0;
    // x方向に2つ選ぶ場合を考える
    // N*M マスから2つ選ぶ方法は　(N*M)^2
    // x軸方向に2つ選ぶ
    for(int i=0;i<M;i++){
        ll dx = i * (M-i);
        sum += dx * (N*N)%mod;
        sum %= mod;
    }
    sum *= COM(N*M-2,K-2);
    ans += sum%mod;
    sum = 0;
    for(int i=0;i<N;i++){
        ll dx = i * (N-i);
        sum += dx%mod* (M*M)%mod;
        sum %= mod;
    }
    sum *= COM(N*M-2,K-2);
    ans += sum%mod;
    cout << ans%mod << endl;
}