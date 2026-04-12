#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;

/*
縦にnマス、横にmマス
ややこしいが、縦方向をxとする。

2つのペアを考える。
x座標の差の絶対値がdになる時、ペアの個数は(n-d)*m*m d=1~n-1
さらに、残りk-2個の組み合わせを考えるとnm-2Ck-2
これらについて、dの総和をとる。
yについても同じことをやれば計算できる。
*/

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];


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
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll ans = 0;

    COMinit();

    ll sum1 = 0;
    rep(d,n){
        sum1 += d*(n-d)*m*m;
        sum1 = sum1 % MOD;
    }
    ll tmp1 = 0;
    tmp1 = COM(n*m-2, k-2);

    //cout << "sum1:" << sum1 << " tmp1:" << tmp1 << endl;
    ans = (sum1*tmp1) % MOD;

    ll sum2 = 0;
    rep(d,m){
        sum2 += d*(m-d)*n*n;
        sum2 = sum2 % MOD;
    }
    ll tmp2 = 0;
    tmp2 = COM(n*m-2, k-2);
    //cout << "sum2:" << sum2 << " tmp2:" << tmp2 << endl;

    ans = (((sum2*tmp2) % MOD) + ans) % MOD;

    cout << ans << endl;  
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
