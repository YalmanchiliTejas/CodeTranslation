#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;

// #define for(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18

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

/* 
NxMのマス目にK個コマを置いた時の
コマ同士のマンハッタン距離の総和を
全てのコマの置き方について合計

XとYは独立なのでまずXについて考える
ある2つのコマの組み合わせを考えると、
それ以外のコマの置き方の組合わせは Combination(N*M-2, K-2) = tmp1
距離がdとなる2つのコマの組み合わせは (N-d) * M * M = tmp2
よってXの総和は tmp1 * (すべてのdについてのtmp2の合計)
*/
int main() {
	// 入力
	ll N,M,K;cin>>N>>M>>K;
    
	// 解法
    COMinit();

    ll X = 0;
    REP(d,N){
        X += d * (N-d) * M * M;
        X %= MOD;
    }
    X *= COM(N*M-2, K-2);
    X %= MOD;

    
    ll Y = 0;
    REP(d,M){
        Y += d * (M-d) * N * N;
        Y %= MOD;
    }
    Y *= COM(N*M-2, K-2);
    Y %= MOD;
    ll ans = X + Y;
    ans %= MOD;

	//出力
	cout << ans << endl;
}
