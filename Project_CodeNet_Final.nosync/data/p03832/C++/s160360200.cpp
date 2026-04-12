#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)


int N;
int A,B,C,D;

i64 nCr[1010][1010];

i64 MOD = 1e9 + 7;

i64 inv_mod(i64 a, i64 m = MOD) {
    i64 b, x, u, q, abs_m, tmp;

    abs_m = (m < 0) ? -m : m;
    b = m;
    x = 1;
    u = 0;
    while (b > 0) {
        q = a / b;
        tmp = u;
        u = x - q * u;
        x = tmp;
        tmp = b;
        b = a - q * b;
        a = tmp;
    }

    return (x < 0) ? abs_m + x : x;
}


int main(){
    cin >> N >> A >> B >> C >> D;
    rep(i,0,1009) rep(j,0,i){
        if(j == 0 || j == i) nCr[i][j] = 1;
        else nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
    }
    vector<i64> fact(1010);
    fact[0] = 1;
    rep(i,1,1010 - 1) fact[i] = (fact[i - 1] * i) % MOD;
    rep(i,1,1010 - 1) fact[i] = inv_mod(fact[i]);

    vector<vector<i64>> dp(B + 1,vector<i64>(N + 1,0));
    dp[A - 1][0] = 1;

    rep(i,A,B){
        rep(j,0,N){
            dp[i][j] = dp[i - 1][j];
            i64 now = 1;
            rep(k,1,j / i){
                now = (now * nCr[N - j + i * k][i]) % MOD;
                if(C <= k && k <= D)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - i * k] * now  % MOD * fact[k]) % MOD;
            }
        }
    }

    cout << dp[B][N] % MOD << endl;
}
