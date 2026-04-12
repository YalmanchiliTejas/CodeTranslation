#include<iostream>
#include<vector>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define ll long long
#define MOD 1000000007

ll calc(ll a, ll b){
    ll ma=a%MOD, mb=b%MOD;
    return (ma*mb) % MOD;
}

int main(){
    int n; std::cin >> n;
    std::vector<ll> a(n), b(n+1,0);
    rep(i,n){
        std::cin >> a[i];
        b[i+1] = b[i] + a[i];
    }

    ll ans=0;
    for(int i=0; i<n; ++i){
        ll s = (b[n] - b[i+1]) % MOD;
        ans += a[i]*s;
        ans %= MOD;
    }

    std::cout << ans << std::endl;
    return 0;
}