#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
const ll MOD = 1000000007;

//関数名：mod_pow
//概要：modつき指数関数
//第一引数a：指数の底
//第二引数b：指数
//第三引数mod：法となる値
//戻り値：a^b(m mod)
long long mod_pow(long long a, long long b, long long mod){
    if(b == 0) return 1;
    if(b % 2 == 0){
        long long d = mod_pow(a,b/2,mod);
        return (d*d)%mod;
    }else return a%mod*mod_pow(a,b-1,mod)%mod;
}

//関数名：mod_combination
//概要：modつき二項係数
//第一引数n：組み合わせの全体
//第二引数r：何個取り出すか
//第三引数mod：法となる値
//戻り値：nCr(m mod)
//計算量O(nlog(mod))
long long mod_combination(long long n,long long r,long long mod){
    if(r > n) return 0;
    if(n == r || r == 0) return 1;
    long long fact1 = 1,fact2 = 1;
    for(long long i = n; i >= n-r+1; i--) fact1 = fact1*i%mod;
    for(long long i = r; i >= 1; i--) fact2 = fact2*i%mod;
    return fact1*mod_pow(fact2,mod-2,mod)%mod;
}


int main(){
    ll n,m; cin >> n >> m;
    ll k; cin >> k;
    ll ans = 0;
    ll comb = mod_combination(n*m-2,k-2,MOD);
    for(ll d = 1; d < n; d++){
        ans += d*(n-d)*m%MOD*m%MOD*comb%MOD;
        ans %= MOD;
    }
    for(ll d = 1; d < m; d++){
        ans += d*(m-d)*n%MOD*n%MOD*comb%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

