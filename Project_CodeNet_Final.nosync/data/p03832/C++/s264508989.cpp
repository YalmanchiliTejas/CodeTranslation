#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

const int maxn = 1e3 + 5;

int fac[maxn], inv[maxn];

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

void pre_comb(){
    fac[0] = 1;
    for(int i = 1;i < maxn;i++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for(int i = maxn - 2;i >= 0;i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}

int comb(int n, int m){
    if(m > n or m < 0) return 0;
    return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int n, a, b, c, d;

int dp[maxn][maxn];

int main(){
    cin >> n >> a >> b >> c >> d;
    memset(dp, 0, sizeof(dp));
    dp[n][a] = 1;
    pre_comb();
    for(int i = n;i >= 0;i--){
        for(int j = a;j <= b;j++){
            add(dp[i][j + 1], dp[i][j]);
            for(int k = c;k <= d and k * j <= i;k++){
                int tmp = 1LL * dp[i][j] * fac[i] % mod * inv[i - k * j] % mod * inv[k] % mod;
                tmp = 1LL * qpow(inv[j], k) * tmp % mod;
                add(dp[i - k * j][j + 1], tmp); 
            }
        }
    }
    cout << dp[0][b + 1] << endl;
    return 0;
}

