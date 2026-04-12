//#define local
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;
#ifdef local
#include "debug.cpp"
#else
#define debug(...)
#endif
const ll mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(10);
    ll n; cin >> n;
    vec<ll> a(n); 
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }
    ll res = 0;
    rep(i,n-1){
        sum = (sum + mod - a[i])%mod;
        res += (a[i] * sum)%mod;
        res %= mod;
    }
    cout << res << endl;
}