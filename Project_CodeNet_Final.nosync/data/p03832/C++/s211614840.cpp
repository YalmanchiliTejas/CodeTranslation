#include <bits/stdc++.h>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};
constexpr int N_MAX = 1000;

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
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    init(n);

    vector<vector<ll>> dp(b+1, vector<ll>(n+1, 0));
    dp[a-1][0] = 1;
    for(int i=a-1;i<b;++i) {
        for(int j=0;j<=n;++j) dp[i+1][j] = dp[i][j];
        for(int j=0;j<=n;++j) {
            if(!dp[i][j]) continue;
            ll g = 1;
            for(int gi=1;gi<=d&&j+(i+1)*gi<=n;++gi) {
                (g *= comb(n-j-(i+1)*(gi-1), i+1)) %= MOD;
                (g *= modpow(gi, MOD-2)) %= MOD;
                if(c <= gi) (dp[i+1][j+(i+1)*gi] += (dp[i][j] * g) % MOD) %= MOD;
            }
            // cout << i << ", " << j << ": " << dp[i][j] << endl;
        }
    }

    cout << dp[b][n] << endl;
}
