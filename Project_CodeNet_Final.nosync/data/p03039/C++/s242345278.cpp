#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> V;
const long long MOD=1000000007LL;
const long long INFL=1LL << 60;
const int INF=1<<29;

const int MAX = 210000;

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


int main(){
    COMinit();
    int N,M,K;
    cin >>N>>M>>K;
    ll ans=0; 
    for(ll i=1;i<N;i++){
        ans+=i*M%MOD*M%MOD*(N-i)%MOD;
        ans%=MOD;
    }
    for(ll j=1;j<M;j++){
        ans+=j*N%MOD*N%MOD*(M-j)%MOD;
        ans%=MOD;
    }
    ans=ans*COM(N*M-2,K-2)%MOD;
    cout<<ans<<endl;



    
    return 0;
}