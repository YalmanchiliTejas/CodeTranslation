#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

class Mod{
  public:
    ll mod;
    // mod must be a prime number
    Mod(ll m){
        mod = m;
    }
    //a^p
    ll modpow(ll a, ll p){
        if(p == 0) return 1;
        if(p%2 == 0){
            ll half = modpow(a, p/2);
            return half * half % mod;
        }
        else return a * modpow(a,p-1) % mod;
    }

    //nCr
    ll comb(ll n, ll r){
        if(r > n-r) return comb(n,n-r);
        ll mul = 1;
        ll div = 1;
        for (int i = 0;i < r;i++){
            mul *= n-i;
            mul %= mod;
            div *= i+1;
            div %= mod;
        }
        return mul * modpow(div,mod-2) % mod;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N,M,K; cin >> N >> M >> K;

    ll mod = 1e9+7;

    Mod m(1e9+7);

    ll t = m.comb(N*M-2,K-2);
    ll ans = 0;

    for (int i = 0;i <= N;i++){
        ans += i*(N-i)*((M*M)%mod)*t;
        ans %= mod;
    }

    for (int i = 0;i <= M;i++){
        ans += i*(M-i)*((N*N)%mod)*t;
        ans %= mod;
    }

    cout << ans << endl;
    
    return 0;

}