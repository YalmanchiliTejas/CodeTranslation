#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll N, M, K;

ll calc(ll L, ll C, ll W){
    ll ret = 0;
    REPi(m,1,L){
        ret += m*(L - m);
        ret %= MOD;
    }

    ret *= W;
    ret %= MOD;
    ret *= W;
    ret %= MOD;
    ret *= C;
    ret %= MOD;

    return ret;
}

//const int MAX_N = 200000;
//
//ll fact[MAX_N+100];
//ll frev[MAX_N+100];
//
//ll rev(ll a, ll p){
//    if(p == 0) return 1;
//    ll tmp = rev(a, p/2);
//    tmp = tmp * tmp % MOD;
//    if(p % 2 == 1) tmp = tmp * a % MOD;
//    return tmp;
//}
//
//
//void calc_fact(){
//    fact[0] = frev[0] = 1;
//    for(int i = 1; i <= MAX_N; i++){
//        fact[i] = (fact[i-1] * i) % MOD;
//        frev[i] = rev(fact[i], MOD-2);
//    }
//}
//
//
//ll comb(int n, int k){
//    if(n < 0 || k < 0 || n < k) return 0;
//    if(n == 0 || k == 0) return 1;
//    return fact[n] * frev[k] % MOD * frev[n-k] % MOD;
//}

//a**b
ll mod_pow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1) ret *= a;
        b >>= 1;
        a *= a;
        a %= MOD;
        ret %= MOD;
    }
    return ret;
}

//xCy
ll comb(ll x, ll y){
    ll top = 1, bot = 1;
    REP(i,y){
        top *= x-i;
        bot *= y-i;
        top %= MOD;
        bot %= MOD;
    }

    ll ret = top * mod_pow(bot, MOD-2);
    return ret % MOD;
}

int main(){
    cin >> N >> M >> K;

    ll ans = 0;

    //in main function
    //fact[0] = frev[0] = 1;
    //for(int i = 1; i <= MAX_N; i++){
    //    fact[i] = (fact[i-1] * i) % MOD;
    //    frev[i] = rev(fact[i], MOD-2);
    //}

    ll C = comb(N*M-2, K-2);

    ans += calc(N, C, M);
    ans %= MOD;
    ans += calc(M, C, N);
    ans %= MOD;

    cout << ans << endl;
    return 0;
}
