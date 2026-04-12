#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mod 1000000007

// Fermat の小定理を用いた F_mod 上での逆元計算x^(mod-2), 蟻本p115
ll Inverse(ll x){
    ll res = 1;
    int n = mod - 2;
    while(n > 0){
        if(n & 1){
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

// iの階乗 = fact[i], main内の階乗計算をする必要がある
#define MAX_FACT 200100
ll fact[MAX_FACT];

ll nCk(int n, int k){
    //　n_C_kの計算, Inverseの中身にもmodを入れないとオーバーフローするので注意, 蟻本p.263
    ll ans = fact[n] * Inverse(fact[k] * fact[n-k] % mod);
    ans %= mod;
    return ans;
}


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    // N <= M にする
    if(N > M){
        int t = N;
        N = M;
        M = t;
    }
    // コストは駒が配置されている任意の2点間のマンハッタン距離の総和

    // 階乗計算
    fact[0]=1;
    for(int i = 1; i < MAX_FACT; ++i) {
        fact[i] = fact[i-1] * i % mod;
    }

    // ある点とある点の距離は (N*M-2)_C_(K-2) 回数えられるので,
    // マス目の任意の2点間のマンハッタン距離の総和に (N*M-2)_C_(K-2) をかけたものが求める総和
    ll ans = 0;
    ll temp;
    // 1*M
    for (int i = 1; i < M; ++i) {
        temp = M - i;
        temp = temp * i % mod;
        ans = ans + temp;
        ans %= mod;
    }

    ll base = ans;
    // N*M
    for (int i = 1; i < N; ++i) {
        temp = i + 1;
        temp = temp * i % mod;
        temp = temp * Inverse(2) % mod;
        temp = temp * M % mod;
        temp = temp * M % mod;
        ans += temp;
        ans %= mod;
        temp = base * 2 % mod;
        temp = temp * i % mod;
        ans += temp;
        ans %= mod;
        ans += base;
        ans %= mod;
    }

    ans *= nCk(N*M-2, K-2);
    ans %= mod;
    
    cout << ans;
    return 0;
}