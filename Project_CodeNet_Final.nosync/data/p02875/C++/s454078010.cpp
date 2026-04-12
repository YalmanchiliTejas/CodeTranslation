#include <iostream>
#include <vector>

using namespace std;

using ll =  long long;

constexpr ll MOD = 998244353;

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

inline ll comb(const ll fact, const ll rfact1, const ll rfact2) {
    return (fact * ((rfact1 * rfact2) % MOD)) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n;
    cin >> n;

    ll ans = modpow(3LL, n);

    ll fact = 1LL, rfact1 = 1LL, rfact2 = 1LL;
    for(ll i=2;i<=n;++i) {
        fact *= i;
        fact %= MOD;
    }
    for(ll i=2;i<=n/2;++i) {
        rfact1 *= modpow(i, MOD-2);
        rfact1 %= MOD;
    }
    rfact2 = rfact1;

    ll pow_2 = modpow(2LL, n/2);
    ll r2 = modpow(2LL, MOD-2);

    for(ll i=n/2+1;i<=n;++i) {
        pow_2 *= r2;
        pow_2 %= MOD;
        rfact1 *= ll(n-i+1);
        rfact1 %= MOD;
        rfact2 *= modpow(i, MOD-2);
        rfact2 %= MOD;
        ans += MOD - (((2 * comb(fact, rfact1, rfact2)) % MOD) * pow_2) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
