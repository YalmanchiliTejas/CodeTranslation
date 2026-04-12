#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> V;
typedef pair<ll,ll> P;
typedef map<ll,ll> M;

#define REP(i,n) for(ll (i) = 0; (i) < (n); ++(i))


signed main(){
    ll n;
    cin >> n;
    V a(n);
    for(auto& x : a)
        cin >> x;

    vector<ll> rui(n+1, 0);
    REP(i,n)rui[i+1] = rui[i] + a[i];

    M f;
    M b;
    REP(i,n+1){
        b[rui[i]] = i;
    }
    for(ll i = n; i >= 0; --i){
        f[rui[i]] = i;
    }
    ll ans = 0;
    for(auto x : f){
        ll pos = x.first;
        if(!(b[pos] - f[pos]))continue;
        ans = max(ans, b[pos] - f[pos]);
    }
    cout << ans << endl;
}

