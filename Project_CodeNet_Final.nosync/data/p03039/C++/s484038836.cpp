#include <bits/stdc++.h>
#define reps(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) for(int i=0;i<a;i++)
typedef long long int ll;
using namespace std;
ll MOD = 1000000007;

const int MAX = 510000;

struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(){
    ll N,M,K;
    cin>>N>>M>>K;
    long long int sum=0;
    for(ll k=1;k<N+1;k++){
        for(ll l=1;l<M+1;l++){
            sum = (sum %MOD) + (M*(((k-1)*k/2+(N-k)*(N-k+1)/2)% MOD)%MOD);
            sum = (sum % MOD) +  (N*(((l-1)*l/2+(M-l)*(M-l+1)/2)% MOD)%MOD);
            
        }
    }
    
    COMinit();
    long long aa = COM(N*M-2,K-2);
    
    sum = (aa%MOD) * (sum%MOD);
    
    sum = (sum % MOD) * modinv(2,MOD)%MOD;
    cout<<(sum % MOD);
    return 0;
}