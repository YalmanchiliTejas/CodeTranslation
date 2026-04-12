#include<bits/stdc++.h>
using namespace std;

const int mod = (int) (1e9)+7;
using ll = long long;

int main()
{
    ll n;
    ll a[300000];
    ll q_sum[300000];
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    q_sum[0] = a[0];
    for(int i = 1; i < n; i++){ 
        q_sum[i] = (q_sum[i-1] + a[i])%mod;
        q_sum[i] %= mod;
    }
    ll ans = 0;
    ll last = q_sum[n-1];
    for(int i = 0; i < n; i++) {
        ans += ((last - q_sum[i])*a[i])%mod;
        ans %= mod;
    }
    if(ans < 0) ans += mod;
    printf("%lld\n", ans); 
}
