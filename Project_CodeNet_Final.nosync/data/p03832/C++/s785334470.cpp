#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;
int dp[1010][1010] = {};

int mod_pow(int x, int n) {
    int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % MOD;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}

const int MAXN = 300010;
int fact[MAXN], inv[MAXN];

void init_fact() {
    fact[0] = 1;
    for(int i=1; i<MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    inv[MAXN - 1] = mod_pow(fact[MAXN - 1], MOD-2);
    for(int i=MAXN - 2; i>=0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
}

int comb(int n, int r) {
    if(r < 0 || n < r) return 0;
    return fact[n] * inv[n-r] % MOD * inv[r] % MOD;
}

signed main(){

    init_fact();

    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){

            if(dp[i][j] == 0) continue;

            // i + 1 人グループは作らない
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;

            if(a <= i + 1 && i + 1 <= b){
                int dot = 1;
                int rest = n - j;

                // i + 1 人グループを k 個作る
                for(int k = c; k * (i + 1) <= rest && k <= d; k++){
                    
                    int mul = comb(rest, k * (i + 1));
                    mul %= MOD;
                    mul *= fact[k * (i + 1)];
                    mul %= MOD;
                    mul *= inv[k];
                    mul %= MOD;
                    mul *= mod_pow(inv[(i + 1)], k);
                    mul %= MOD;
                    dp[i + 1][j + (i + 1) * k] += mul * dp[i][j];
                    dp[i + 1][j + (i + 1) * k] %= MOD;
                }
            }
        }
    }

    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << dp[n][n] << endl;
    return 0;
}