#include <iostream>

using namespace std;

using ll =  long long;

constexpr ll MOD = 998244353;
constexpr int N_MAX = 10000000;

ll modpow(ll a, ll t) {
    ll ret = 1LL;
    while(t){
        if(t & 1LL){
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        t >>= 1;
    }
    return ret;
}

ll fact[N_MAX+1], rfact[N_MAX+1];

ll perm(ll n, ll r){
    return (fact[n] * rfact[r]) % MOD;
}

ll comb(ll n, ll r){
    return (perm(n, r) * rfact[n-r]) % MOD;
}

void init(ll n){
    fact[0] = fact[1] = 1;
    rfact[0] = rfact[1] = 1;
    for(int i=2;i<=n;++i) {
        fact[i] = (fact[i-1] * (ll)i) % MOD;
        rfact[i] = 1;
        ll k = MOD-2;
        ll a = fact[i];
        while(k > 0){
            if(k & 1){
                rfact[i] *= a;
                rfact[i] %= MOD;
            }
            a *= a;
            a %= MOD;
            k  >>= 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n;
    cin >> n;
    init(n);

    ll ans = modpow(3LL, n);
    ll pow_2 = modpow(2LL, n/2);
    ll r2 = modpow(2LL, MOD-2);

    for(ll i=n/2+1;i<=n;++i) {
        pow_2 *= r2;
        pow_2 %= MOD;
        ans += MOD - (((2 * comb(n, i)) % MOD) * pow_2) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
