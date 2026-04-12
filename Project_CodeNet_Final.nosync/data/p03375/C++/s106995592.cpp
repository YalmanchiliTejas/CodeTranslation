#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long int;

ll MOD;
const int MAXN = 3010;
ll comb[MAXN + 10][MAXN + 10];

ll mod_pow(ll N, ll K, ll mod=MOD) {
    ll ret = 1; N %= mod;
    for(; K>0; K>>=1) {
        if(K & 1) (ret *= N) %= mod;
        (N *= N) %= mod;
    }
    return ret;
}

void init() {
    for(int i=0; i<MAXN; i++) {
        comb[i][0] = 1;
        for(int j=1; j<MAXN; j++) {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
        }
    }
}

ll dp[3010][3010], ways[3010], ans;
int main() {
    int N; cin >> N >> MOD; init();// MOD はグローバル
    // dp (ways2 を求める)
    dp[0][0] = 1;
    for(int i=1; i<=N; i++) for(int j=0; j<=i; j++) {
        if(j > 0) (dp[i][j] += dp[i-1][j-1]) %= MOD;
        (dp[i][j] += dp[i-1][j] * (j+1)) %= MOD;
    }
    // ways1 を求め、答えに足す
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=i; j++) {
            (ways[i] += dp[i][j] * mod_pow(2, (N-i)*j)) %= MOD;
        }
        (ways[i] *= mod_pow(2, mod_pow(2, N-i, MOD-1))) %= MOD;
        ll val = ways[i] * comb[N][i] % MOD;
        if(i % 2 == 0) ans = (ans + val      ) % MOD;
        else           ans = (ans - val + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}