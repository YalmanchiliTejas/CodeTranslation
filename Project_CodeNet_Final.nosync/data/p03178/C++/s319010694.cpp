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

#define fs first
#define sc second

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1e9+7;
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


ll dp[101000][110][2];

int main(){
    string K;
    cin >> K;
    int D;
    cin >> D;

    for(int i = 0; i < 101000; i++){
        for(int k = 0; k < 110; k++){
            for(int j = 0; j < 2; j++){
                dp[i][k][j] = 0;
            }
        }
    }

    dp[0][0][1] = 1;
    for(int i = 0; i < K.length(); i++){
        int d = K[i] - '0';

        for(int j = 0; j <= D; j++){
//            cout << dp[i][j][0] << " " << dp[i][j][1] << " " << i << " " << j << endl;
            // Kに縛られていない
            for(int k = 0; k <= 9; k++){
                dp[i+1][(j+k) % D][0] = add(dp[i+1][(j+k) % D][0], dp[i][j][0]);
            }

            for(int k = 0; k < d; k++){
                dp[i+1][(j+k) % D][0] = add(dp[i+1][(j+k) % D][0], dp[i][j][1]);
            }

            dp[i+1][(j+d) % D][1] = add(dp[i+1][(j+d) % D][1], dp[i][j][1]);
        }
//        cout << endl;
    }

    cout << sub(add(dp[K.length()][0][0], dp[K.length()][0][1]), 1) << endl;

    return 0;
}