#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

ll fac[200007],finv[200007],inv[200007];
void cominit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<200007;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll com(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cominit();
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(ll i=0;i<n;i++){
    	for(ll j=0;j<m;j++){
    		ll u = n - 1 - i;
    		ll v = m - 1 - j;
    		ll num = 0;
    		num += (((i * (i + 1)) % mod) * m)%mod;
    		num += (((j * (j + 1)) % mod) * n)%mod;
    		num += (((u * (u + 1)) % mod) * m)%mod;
    		num += (((v * (v + 1)) % mod) * n)%mod;
    		num %= mod;
    		num *= com(n * m - 2, k - 2);
    		num %= mod;
    		ans += num;
    		ans %= mod;
    	}
    }
    ans *= modpow(4LL, mod - 2);
    ans %= mod;
    ans += mod;
    ans %= mod;

    cout << ans << endl;
    return 0;
}
