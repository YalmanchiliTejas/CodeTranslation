#include<bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int mod = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    COMinit();

    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(n-i)*i*m*m*COM(n*m-2,k-2);
        ans%=mod;
    }
    for(int i=0;i<m;i++){
        ans+=(m-i)*i*n*n*COM(n*m-2,k-2);
        ans%=mod;
    }
    cout<<ans<<endl;
}