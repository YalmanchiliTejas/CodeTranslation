#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define sum(a) accumulate(a.begin(),a.end(),0LL)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];

    //ll n = 1e5; vector<ll> a(1e5,1e9);
    
    ll mod = ll(1e9+7);

    ll suma = 0;
    for(long long i = 0; i < n; i++){
        suma += a[i];
    }

    
    ll ans = 0;
    for(long long j = 0; j < n-1; j++){
        suma -= a[j];
        ans = ans + (suma % mod * a[j]) % mod;
    }
    ans %= mod;
    put(ans);
}