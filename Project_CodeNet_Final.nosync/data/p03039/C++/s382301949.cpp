#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
//const ll MOD=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI = 2.0*acos(0);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

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

ll pat(ll n,ll m){
    return ((n*m%MOD*(n+m-2ll))%MOD)*inv[2]%MOD;
}

ll pat2(ll n){
    return ((n*(n+1)%MOD*inv[2])%MOD*-1+MOD)%MOD;

}

void solve(int ca){
    COMinit();
    ll N,M,K; cin>>N>>M>>K;

    ll ans=0ll;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ll cnt=0ll;
            (cnt+=pat(i+1,j+1))%=MOD;
            (cnt+=pat(i+1,M-j))%=MOD;
            (cnt+=pat(N-i,j+1))%=MOD;
            (cnt+=pat(N-i,M-j))%=MOD;

            (cnt+=pat2(i))%=MOD;
            (cnt+=pat2(j))%=MOD;
            (cnt+=pat2(N-i-1))%=MOD;
            (cnt+=pat2(M-j-1))%=MOD;

            (cnt*=COM(N*M-2,K-2))%=MOD;

            (ans+=cnt)%=MOD;
        }
    }
    (ans*=inv[2])%=MOD;
    cout<<ans<<endl;

}

//#define MULTI
int main() {
#ifdef MULTI
    int N; cin>>N;
    for (int i = 0; i < N; ++i) {
        solve(i+1);
    }
#else
    solve(0);
#endif
    return 0;
}
