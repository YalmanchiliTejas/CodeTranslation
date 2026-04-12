#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep2(i, n) for(ll i = 2; i <=(ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 199;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//順列計算
ll PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    ll leastidx[3*m+1];
    ll sum[3*m+1];
    rep0(i, 3*m) leastidx[i] = 0;
    sum[0] = 0;
    ll a = x;
    ll ans = 0;
    rep1(i, n){
        //cout << a << endl;
        sum[i] = sum[i-1] + a;
        if(leastidx[a] > 0){
            ll s_cycle = leastidx[a];
            ll cycle_len = i - s_cycle;
            ll cycle_sum = sum[i] - sum[s_cycle];
            ll cycle_num = (n - i) / cycle_len;
            ll left = (n - i) % cycle_len;
            ans = sum[i] + cycle_sum*cycle_num + sum[s_cycle+left] - sum[s_cycle];
            cout << ans << endl;
            return 0;        
        }
        leastidx[a] = i;
        a = (a*a) % m;
    }
    ans = sum[n];
    cout << ans << endl;
    return 0;
}