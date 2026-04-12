#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


const ll mod = 1000000007;
ll fact[210200];
ll invfact[210200];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a-b);
}


inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

inline ll pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll perm(ll n, ll k){
    return mul(fact[n], invfact[n-k]);
}

ll comb(ll n, ll k){
    if(k == 0){
        return 1;
    }
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}


ll N, M, K;
ll calc(ll i, ll j){
    ll res = 0;
    res = add(res, (N-i+M-j-2)*(N-i)*(M-j) / 2);
    res = add(res, (M-j+i-1)*(i+1)*(M-j) / 2);
    res = add(res, (N-i+j-1)*(j+1)*(N-i) / 2);
    res = add(res, (i+j)*(i+1)*(j+1) / 2);
    res = sub(res, (N-i-1)*(N-i)/2);
    res = sub(res, (M-j-1)*(M-j)/2);
    res = sub(res, (j+1)*j/2);
    res = sub(res, (i+1)*i/2);

    return res;
}


int main(){
    cin >> N >> M >> K;

    ll res = 0;
    make_fact(210000);
    make_invfact(210000);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            res = add(res, mul(calc(i, j), comb(N*M-2, K-2)));
        }
    }

    res = mul(res, mod_inv(2));

    cout << res << endl;


    return 0;
}
