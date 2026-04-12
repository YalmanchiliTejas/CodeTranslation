#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cstdio>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<long int, long int>

// a^n mod を計算する
long int modpow(long int a, long int n, long int mod) {
    long int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

long int modcomb(long int a, long int b, long int mod){
    long int res = 1;
    for(long int i = a; i > a - b; i--){
        res *= i % mod;
        res %= mod;
    }
    res %= mod;
    for(long int i = 1; i <= b; i++){
        long int i_inv = modpow(i, mod - 2, mod);
        res *= i_inv % mod;
        res %= mod;
    }
    res %= mod;
    // cout << res << endl;
    return res;
}


int main(){
    long int n, m, k;
    cin >> n >> m >> k;
    const long int mod = 1000000007;
    long int x = 0;
    long int y = 0;
    for (long int i = 1; i <= n - 1; i++){
        x += (n - i) * (m * m) * i;
        x %= mod;
    }
    for (long int i = 1; i <= m - 1; i++){
        y += (m - i) * (n * n) * i;
        y %= mod;
    }
    long int ans = x + y;
    ans %= mod;
    ans *= modcomb(n * m - 2, k - 2, mod);
    ans %= mod;
    cout << ans << endl;
}
