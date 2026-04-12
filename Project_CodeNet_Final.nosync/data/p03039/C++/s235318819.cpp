#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < n ; i++ )
#define For(i, a, b) for(int i = (a); i < (b) ; i++ )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll mod = 1e9 + 7;

ll power_mod(ll a, ll power){
    ll value = 1;
    
    while(power != 0){
        if(power & 1) value = (value * a) % mod;
        a = (a * a) % mod;
        power = power >> 1;
     
    }

    return value % mod;
}

//https://qiita.com/ofutonfuton/items/92b1a6f4a7775f00b6ae

ll combination(ll n, ll r){
    ll numerator = 1;
    ll denomenator = 1;

    rep(i, r){
        (numerator *= ll(n - i)) %= mod;
        (denomenator *= power_mod(ll(i + 1), ll(mod - 2))) %= mod;
    }
    
    return (numerator * denomenator) % mod;
}

int main(void){
    //int N, M, K;
    ll N, M, K;
    cin >> N >> M >> K;
    //scanf("%d %d %d", &N, &M, &K);
    ll cost_x = 0;
    ll cost_y = 0;
    ll comb = combination(ll(N * M - 2), ll(K - 2));

    For(d, 1, N){
        (cost_x += ll(d * (N - d)) % mod) %= mod;
    }

    For(d, 1, M){
        (cost_y += ll(d * (M - d)) % mod) %= mod;
    }

    (cost_x *= ll(M * M) % mod) %= mod;
    (cost_y *= ll(N * N) % mod) %= mod;
    ll cost = (cost_x + cost_y) % mod;

    cout << (cost * comb) % mod << endl;

    return 0;
}