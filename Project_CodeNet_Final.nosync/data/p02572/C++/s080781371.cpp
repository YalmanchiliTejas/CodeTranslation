#include<iostream>
#include<vector>
#include<string>

using ll = long long;
const ll MOD = 1000000007;

int main(){
    ll n;
    std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::vector<ll> csum(n);
    csum[0] = a[0] % MOD;
    for(int i = 1; i < n; i++){
        csum[i] = (csum[i - 1] + a[i]) % MOD;
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans += (a[i] % MOD) * ((csum[n - 1] - csum[i] + MOD) % MOD);
        ans = ans % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}
