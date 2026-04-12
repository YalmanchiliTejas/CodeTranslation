#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

//二項係数
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

int main() {
    ll N,M,K;
    cin>>N>>M>>K;
    COMinit();
    ll P=COM(N*M-2,K-2);
    ll Q1=0,Q2=0;
    for(ll i=1;i<=N;i++){
        Q1+=(i-1)*i/2+(N-i)*(N-i+1)/2;
        Q1%=MOD;
    }
    Q1*=M;
    Q1%=MOD;
    Q1*=M;
    Q1%=MOD;
    for(ll i=1;i<=M;i++){
        Q2+=(i-1)*i/2+(M-i)*(M-i+1)/2;
        Q2%=MOD;
    }
    Q2*=N;
    Q2%=MOD;
    Q2*=N;
    Q2%=MOD;
//cout<<Q1<<" "<<Q2<<endl;
    ll Q=Q1+Q2;
    Q%=MOD;
    Q*=finv[2];
    Q%=MOD;
    Q*=P;
    Q%=MOD;
    cout<<Q<<endl;
}