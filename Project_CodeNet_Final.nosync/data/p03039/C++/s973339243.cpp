#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}

const int MAX = 510000;


ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD; //i!の計算
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD; //iの逆元の計算
        finv[i] = finv[i - 1] * inv[i] % MOD; //i!の逆元の計算
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    ll N, M, K; cin >> N >> M >> K;
    ll ans=0;
    COMinit();
    for(int d=1; d<=N-1; d++){
        ans=(ans+d*(N-d)%MOD*M%MOD*M%MOD*COM(N*M-2, K-2)%MOD)%MOD;
    }
    for(int d=1; d<=M-1; d++){  
        ans=(ans+d*(M-d)%MOD*N%MOD*N%MOD*COM(N*M-2, K-2)%MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}