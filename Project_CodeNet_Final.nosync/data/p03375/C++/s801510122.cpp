#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

ll MOD;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};
constexpr int N_MAX = 3001;

ll s[N_MAX][N_MAX], pow2[N_MAX*N_MAX], powpow2[N_MAX];

void init_stirling(int n, int m) {
    for(int i=0;i<=n;++i) s[i][0] = 1;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            s[i][j] = (s[i-1][j-1] + (s[i-1][j]*(j+1)) % MOD) % MOD;
        }
    }
}

ll fact[N_MAX], rfact[N_MAX];

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

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n >> MOD;
    init(n);
    init_stirling(n, n);

    pow2[0] = 1LL;
    for(int i=0;i<n*n;++i) {
        pow2[i+1] = (2LL * pow2[i]) % MOD;
    }
    powpow2[0] = 2LL;
    for(int i=0;i<n;++i) {
        powpow2[i+1] = (powpow2[i] * powpow2[i]) % MOD; // 2^(2^n) = 2^(2^(n-1)) * 2^(2^(n-1))
    }

    ll ans = powpow2[n];
    for(ll i=1;i<=n;++i) {
        ll tmp = 0LL;
        for(ll j=0;j<=i;++j) {
            if(pow2[(n-i)*j] == 0) {
                pow2[(n-i)*j] = modpow(2LL, (n-i)*j);
            }
            tmp += pow2[(n-i)*j] * s[i][j];
            tmp %= MOD;
        }
        tmp *= comb(n, i);
        tmp %= MOD;
        tmp *= powpow2[n-i];
        tmp %= MOD;
        if(i % 2) {
            ans += MOD - tmp;
        } else {
            ans += tmp;
        }
        ans %= MOD;
    }

    cout << ans << endl;

}
