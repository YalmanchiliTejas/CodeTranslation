#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void) {
    constexpr ll MOD = 1e9 + 7;

    vector<ll> fact(2e6+1, 1), ifact(2e6+1, 1);
    for(ll i=2; i<=2e6; i++) fact[i] = i * fact[i-1] % MOD;
    {
        ll &r = ifact[2e6], a = fact[2e6], b = MOD-2;
        while(b) {
            if(b&1) (r *= a) %= MOD;
            (a *= a) %= MOD;
            b >>= 1;
        }
    }
    for(ll i=2e6; i>0; i--) ifact[i-1] = i * ifact[i] % MOD;
    
    auto powm = [&](ll a, ll b) {
        ll r = 1;
        while(b) {
            if(b&1) (r *= a) %= MOD;
            (a *= a) %= MOD;
            b >>= 1;
        }
        return r;
    };

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<ll> dp(n+1);
    dp[n] = 1;
    for(ll i=a; i<=b; i++) {
        vector<ll> pre = dp;
            for(ll k=n; k>=0; k--) {
        for(ll j=c; j<=min(d, k/i); j++) {
            // k - i*j >= 0
            // j <= k/i
                if(k - i*j >= 0) {
                    ll t = 1;
                    (t *= pre[k]) %= MOD;
                    // kCij * (ij)! / (i!)^j / j!
                    // k! / (k-ij)! j! (i!)^j
                    (t *= fact[k]) %= MOD;
                    (t *= ifact[k-i*j]) %= MOD;
                    (t *= ifact[j]) %= MOD;
                    (t *= powm(ifact[i], j)) %= MOD;

                    (dp[k - i*j] += t) %= MOD;
                }
        }
            }
    }
    cout << dp[0] << endl;
}
