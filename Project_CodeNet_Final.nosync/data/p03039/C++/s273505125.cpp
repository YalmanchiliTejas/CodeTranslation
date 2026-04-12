#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
const ll MAX = 210000;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void Main(){
    COMinit();
    ll n;cin>>n;
    ll m;cin>>m;
    ll k;cin>>k;
    For(i,1,n+1){
        ll cost=i*(n-i)*m%MOD*m%MOD*COM(n*m-2,k-2)%MOD;
        ans=(ans+cost)%MOD;
    }
    For(i,1,m+1){
        ll cost=i*(m-i)*n%MOD*n%MOD*COM(n*m-2,k-2)%MOD;
        ans=(ans+cost)%MOD;
    }
    cout<<ans<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}