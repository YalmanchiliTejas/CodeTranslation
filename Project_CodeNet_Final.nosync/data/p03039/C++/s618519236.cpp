#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll MOD = 1e9+7;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)


ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);


    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }

    ll N, M, K;
    cin >> N >> M >> K;

    ll ans_v = 0;
    ll ans_h = 0;
    
    ll A = N * M;

    for(ll i = 0; i < N; i++){
        ans_v = (ans_v + (((i * (N-i))%MOD) * ((M * M)%MOD)) % MOD ) %MOD;
    }

    for(ll i = 0; i < M; i++){
        ans_h = (ans_h + (((i * (M-i))%MOD) * ((N * N)%MOD)) % MOD ) %MOD;
    }

    ll ans = 0;
    ans = (ans_v + ans_h) % MOD;
    ans = (ans * comb(A-2, K-2))% MOD;

    cout << ans << endl;

    return 0;
}

