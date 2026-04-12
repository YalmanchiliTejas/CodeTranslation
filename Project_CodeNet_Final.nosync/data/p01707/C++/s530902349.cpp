#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007LL;

// 階乗 (mod とりバージョン)
ll fact_mod(ll n, ll mod) {
    ll f = 1; for(long long i = 2; i <= n; i++) f = f * (i % MOD) % MOD;
    return f;
}

// 繰り返し二乗法 (modの世界での累乗)
// ※modが素数の場合、この関数で(mod - 2)乗したら、mod割り算ができるよ！
// (参考問題: ABC034 C問題など)
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % mod; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % mod;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}

// 組み合わせ nCr を求める (modあり)
ll combination_mod(ll n, ll r, ll mod) {
    if(r > n-r) r = n-r;
    if(r == 0) return 1;
    ll a = 1;
    for(long long i = 0; i < r; i++) a = a * ((n-i) % mod) % mod;
    ll b = mod_pow(fact_mod(r, mod), mod-2, mod);
    return (a % mod) * (b % mod) % mod;
}

signed main(){

    while(1){

        long long n, d, x; cin >> n >> d >> x;
        
        if(!n) break;

        //一日一個食べるという制約のもと
        //dp[i][j] := i日かかってクッキーj個食べる方法の通り数
        vector<vector<long long> > dp(n + 1, vector<long long> (n + 1, 0LL));
        dp[0][0] = 1LL;
        //cout << dp[0][0] << endl;

        for(long long i = 0LL; i < n; i++){

            //累積和
            vector<long long> acc(n + 1, 0LL);
            acc[0] = dp[i][0];
            //cout << acc[0] << " ";
            for(long long j = 1LL; j <= n; j++){
                acc[j] = (acc[j - 1] + dp[i][j]) % MOD;
                //cout << acc[j] << " ";
            }
            //cout << endl;

            for(long long j = i + 1LL; j <= n; j++){

                //食べる個数は 1 <= c <= x - 1
                long long r = j - 1LL;
                long long l = max(0LL, j - x + 1LL);

                if(l == 0) dp[i + 1][j] += acc[r] % MOD;
                else{
                    assert(r >= l - 1);    
                    dp[i + 1][j] += (acc[r] - acc[l - 1] + MOD) % MOD;
                }

                dp[i + 1][j] %= MOD;
                assert(dp[i + 1][j] >= 0);
            }
        }

        /*for(long long i = 0; i <= n; i++){
            for(long long j = 0; j <= n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        


        long long ans = 0LL;
        for(long long i = 1LL; i <= n && i <= d; i++){
            //cout << i << endl;
            ans += ((dp[i][n] % MOD) * (combination_mod(d, i, MOD) % MOD)) % MOD;
            ans %= MOD;
        }

        cout << ans << endl;
    }

    return 0;
}
