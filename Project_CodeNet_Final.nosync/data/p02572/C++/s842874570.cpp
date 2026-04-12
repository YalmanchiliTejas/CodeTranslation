#include "bits/stdc++.h"

using namespace std;

typedef long double ld;
typedef long long ll;

#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

template<typename T, typename U> bool ckmin(T &a, U b){ return b < a ? a = b, true : false; }
template<typename T, typename U> bool ckmax(T &a, U b){ return b > a ? a = b, true : false; }

const ll MOD = 1e9 + 7;

ll n;
vector<ll> v;
ll exp(ll a, ll b){
    if(b == 0) return 1;
    ll tmp = exp(a, b/2);
    tmp *= tmp; tmp %= MOD;
    if(b & 1) tmp *= a;
    return tmp%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.assign(n, 0);
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i]; sum += v[i];
        sum %= MOD;
    }
    ll res = sum * sum;
    for(int i = 0; i < n; ++i){
        res -= (v[i] * v[i])%MOD;
        res = ((res%MOD) + MOD)%MOD;
    }
    cout << (res * exp(2, MOD - 2))%MOD;
    return 0;
}