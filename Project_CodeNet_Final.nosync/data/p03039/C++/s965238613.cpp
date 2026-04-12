#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<(b);++i)
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const ll MAX = 200000;
 
ll fact[MAX],finv[MAX];
ll inv(ll x){
    int res = 1;
    int k = MOD - 2;
    ll y = x;
    while(k){
        if(k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k >>= 1;
    }
    return res;
} 
 
int N,M,K;
int main() {
    cin >> N >> M >> K;
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i,2,MAX) {
        fact[i] = fact[i-1] * i % MOD;
        finv[i] = inv(fact[i]) % MOD;
    }
    ll C = fact[N*M-2] * finv[K-2] % MOD * finv[N*M-K] % MOD;

    ll d = 0;
    // 行の差がd(i=1~N-1)の2点の選び方数 * 2点が選ばれる回数
    // d * (N-d) * M * M
    for(ll i=0; i < N; ++i) (d += (i * (N-i) % MOD * M) % MOD * M % MOD) %= MOD;
 
    // 列
    for(ll i=0; i < M; ++i) (d += (i * (M-i) % MOD * N) % MOD * N % MOD) %= MOD;
 
    cout << d * C % MOD << endl;
 
    return 0;
}