#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 998244353;
ll fact[200200];
ll invfact[200200];

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
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

ll dp[3100][3100];

int main(){
    int N;
    cin >> N;

    ll a[3100];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    for(int i = 0; i < N; i++){
        dp[i][i] = a[i];
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j + i < N; j++){
            dp[j][j+i] = max(a[j] - dp[j+1][j+i], a[j+i] - dp[j][j+i-1]);
        }
    }

    cout << dp[0][N-1] << endl;

    

    return 0;
}