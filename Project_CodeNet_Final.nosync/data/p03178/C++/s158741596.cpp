#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const ll NMAX = 10001;
const ll DMAX = 101;
const ll MOD = 1e9 + 7;

ll dp[NMAX][DMAX][2] = {0};

int main()
{
    string k;
    cin>>k;
    ll D, n, num;
    cin>>D;
    n = k.length();
    dp[0][0][1] = 1;
    for(ll i = 0 ; i < n ; i++){
        num = k[i] - '0';
        for(ll j = 0 ; j < D ; j++){
            for(ll p = 0 ; p < 10 ; p++){
                dp[i + 1][(j + p) % D][0] += dp[i][j][0];
                dp[i + 1][j][0] %= MOD;
            }
            dp[i + 1][(j + num) % D][1] += dp[i][j][1] % MOD;
            for(ll p = 0 ; p < num ; p++){
                dp[i + 1][(j + p) % D][0] += dp[i][j][1];
                dp[i + 1][j][0] %= MOD;
            }
        }
    }

    cout<< (dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD;
    return 0;
}
