#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int N, M, K;


const int MAX_N = 200000;

ll fact[MAX_N+100];
ll frev[MAX_N+100];

ll rev(ll a, ll p){
    if(p == 0) return 1;
    ll tmp = rev(a, p/2);
    tmp = tmp * tmp % MOD;
    if(p % 2 == 1) tmp = tmp * a % MOD;
    return tmp;
}


void calc_fact(){
    fact[0] = frev[0] = 1;
    for(int i = 1; i <= MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        frev[i] = rev(fact[i], MOD-2);
    }
}


ll comb(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 || k == 0) return 1;
    return fact[n] * frev[k] % MOD * frev[n-k] % MOD;
}

ll solve(ll n, ll m){
    ll ret = 0;
    for(ll d = 1; d < m; d++){
        ret += d*(m-d);
        ret %= MOD;
    }

    ret *= n*n;
    ret %= MOD;
    ret *= comb(n*m-2, K-2);
    ret %= MOD;
    return ret;
}

int main(){
    cin >> N >> M >> K;

    ll ans = 0;

    //in main function
    fact[0] = frev[0] = 1;
    for(int i = 1; i <= MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        frev[i] = rev(fact[i], MOD-2);
    }

    ans += solve(N, M);
    //cout << ans << endl;
    ans += solve(M, N);

    cout << ans%MOD << endl;
    return 0;
}
