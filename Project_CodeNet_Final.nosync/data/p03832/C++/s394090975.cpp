#include <iostream>
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int N, A, B, C, D;
ll dp[1010][1010], perm[1010][1010], fact[1010];

ll mod_pow(int n, int k) {
    ll ret = 1, val = n, rest = k, s = 0;
    while(rest != 0) {
        if(s != 0) (val *= val) %= MOD;
        if(k >> s & 1) {
            rest -= (1 << s);
            (ret *= val) %= MOD;
        }
        s++;
    }
    return ret;
}

int main() {
    fact[0] = 1;
    for(int i=1; i<1010; i++) fact[i] = (i * fact[i-1]) % MOD;
    for(int i=0; i<1010; i++) {
        for(int j=0; j<=i; j++) {
            perm[i][j] = (fact[i] * mod_pow(fact[i-j], MOD-2)) % MOD;
        }
    }

    cin >> N >> A >> B >> C >> D;
    dp[A-1][0] = 1;
    for(int i=A; i<=B; i++) {
        for(int j=0; j<=N; j++) {
            (dp[i][j] += dp[i-1][j]) %= MOD;
            for(int k=C; j-k*i >= 0 && k <= D; k++) {
                // printf("(%d, %d, %d): perm[%d][%d] = %lld, fact[k] = %lld, (i!)^k = %lld\n", i, j, k, N-j+k*i, k*i, perm[N-j+k*i][k*i], fact[k], mod_pow(fact[i], k));
                ll val = (dp[i-1][j-k*i] * perm[N-j+k*i][k*i]) % MOD;
                (val *= mod_pow(fact[k], MOD-2)) %= MOD;
                (val *= mod_pow(mod_pow(fact[i], k), MOD-2)) %= MOD;
                (dp[i][j] += val) %= MOD;
            }
            // printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
        }
    }
    cout << dp[B][N] << endl;
    return 0;
}