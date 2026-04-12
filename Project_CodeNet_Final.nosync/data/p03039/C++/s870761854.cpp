#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int MAX = 200010;

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
//main関数にCOMinit();を忘れない


int main(){
    COMinit();

    ll N,M,K; cin>>N>>M>>K;
    ll ans=0ll;
    for(int i=0;i<N;++i){
        for (int j = 0; j < M; ++j) {
            ll tmp=((N-i)*(M-j)%MOD)*(i+j)%MOD;
            if(i>0&&j>0) tmp*=2ll;
            (ans+=tmp)%=MOD;
        }
    }

    (ans*=COM(N*M-2,K-2))%=MOD;

    cout<<ans<<endl;

    return 0;
}
