#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

vector<long long int> inverse;
vector<long long int> f, f_inverse;

void factorial_Initialize(int max){
    vector<long long int> a(max+1,1);
    inverse = a;
    f = a;
    f_inverse = a;

    for (int i=2; i<=max; i++){
        inverse[i]   = MOD - inverse[MOD % i] * (MOD / i) % MOD;
        f[i]         = f[i-1]         * i          % MOD;
        f_inverse[i] = f_inverse[i-1] * inverse[i] % MOD;
    }
}

long long int nCr(int n, int r){
    if(n < r || r < 0) return 0;
    if (n >= f.size()){
        factorial_Initialize(n);
    }
    return f[n] * f_inverse[r] % MOD * f_inverse[n-r] % MOD;
}

long long int modpow(long long int b, long long int p){// modinv(x) = modpow(x, MOD-2)
    long long int num = 1, power = b;
    for(int i=0; i<=30; i++){
        if((p>>i) & 1){
            num *= power;
            num %= MOD;
        }

        power *= power;
        power %= MOD;
    }
    return num;
}


int main(){
    long long int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    factorial_Initialize(n);

    vector<vector<int>> dp(n+1,vector<int>(n+1));
    dp[a-1][0] = 1;
    for(int i=a; i<=b; i++){
        for(int j=0; j<=n; j++){
            if(dp[i-1][j] == 0) continue;

            dp[i][j] += dp[i-1][j];// k = 0
            dp[i][j] %= MOD;

            for(int k=c; k<=d; k++){
                if(j + i*k > n) break;

                dp[i][j + k*i] += dp[i-1][j]
                               * nCr(n-j,k*i)                 % MOD
                               * f[k*i]                       % MOD
                               * modpow(modpow(f[i],MOD-2),k) % MOD
                               * modpow(f[k],MOD-2)           % MOD;
                dp[i][j + k*i] %= MOD;
            }
        }
    }

    cout << dp[b][n] << endl;
    return 0;
}