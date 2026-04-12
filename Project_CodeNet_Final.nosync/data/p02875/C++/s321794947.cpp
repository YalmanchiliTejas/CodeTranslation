#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll inv[5000001];
int main(){
    int n;
    scanf("%d",&n);
    int k = n/2+1;
    ll bad = 0;
    ll multiplier = 1;
    ll ans = 1;
    ll x = 1;
    inv[1] = 1;
    for (int i = 2; i <= n-k+1; i++){
        inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
    }
    for (int i = 0; i < n; i++) {
        ans *= 3;
        ans %= mod;
    }
    for (int i = n; i >= k; i--){
        bad += multiplier*x;
        bad %= mod;
        multiplier *= i;
        multiplier %= mod;
        multiplier *= inv[n-i+1];
        multiplier %= mod;
        x *= 2;
        x %= mod;
    }
    ans -= 2*bad;
    ans = ((ans%mod)+mod)%mod;
    printf("%lld",ans);
}
