#include<bits/stdc++.h>
using namespace std;

int mod = 1'000'000'007;

long long getComb(int x, int y){
    //逆元を求める
    vector<long long> rep(x+1, 0);
    rep[1] = 1;
    for (int i = 2; i < x+1; i++){
        rep[i] = (mod - (mod / i)) * rep[mod % i] % mod;
    }
    //nCr
    vector<long long> c(x+1, 0);
    c[0] = 1;
    for (int i = 1; i < x + 1; i++){
        c[i] = c[i - 1] * ((x - i + 1) * rep[i] % mod) % mod;
        c[i] %= mod;
    }
    return c[y];
}

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    long long ans = 0;
    for (int i = 1; i < m; i++){
        ans += i * ((m - i) * (n * n % mod) % mod) % mod;
        ans %= mod;
    }
    for (int i = 1; i < n; i++){
        ans += i * ((n - i) * (m * m % mod) % mod) % mod;
        ans %= mod;
    }
    ans *= getComb(m * n - 2, k - 2);
    ans %= mod;
    cout << ans << endl;
}

