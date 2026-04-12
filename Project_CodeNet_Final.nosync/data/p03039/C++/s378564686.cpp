#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
ll powmod(ll x,ll n){
    if(n == 0)return 1;
    ll ans = powmod(x*x%MOD,n/2);
    if(n % 2)ans = ans * x % MOD;
    return ans;
}
ll divmod(ll a,ll b){
    return ((a%MOD) * (powmod(b,MOD-2)%MOD)) % MOD;
}
ll combi(ll n,ll r){
    ll num = 1;
    for(ll i = 1;i <= r;i++){
        num = divmod((n-i+1)*num,i);
    }
    return num;
}
ll mul(ll i){
    return (i * (i+1) / 2) % MOD;
}
main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll table[N][M] = {};
    ll tb1[N] = {}, tb2[M] = {};
    rep(i,0,N){
        tb1[i] = mul(i) + mul(N-i-1);
        //cout << tb1[i] << " \n"[i==N-1];
    }
    rep(i,0,M){
        tb2[i] = mul(i) + mul(M-i-1);
        //cout << tb2[i] << " \n"[i==M-1];
    }

    rep(i,0,N)rep(j,0,M){
        table[i][j] = (tb1[i] * M) % MOD + (tb2[j] * N) % MOD;
        //cout << table[i][j] << " \n"[j==M-1];
    }
    ll sum = 0, r = combi(N * M - 2, K - 2);
    //cout << r << endl;
    rep(i,0,N)rep(j,0,M){
        sum += (table[i][j] * r) % MOD;
        sum %= MOD;
    }
    sum = divmod(sum, 2);
    cout << sum << endl;
}