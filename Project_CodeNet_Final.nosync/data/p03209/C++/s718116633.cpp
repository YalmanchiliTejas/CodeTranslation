#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<ll> p(55), a(55);

ll f(ll n, ll x){
    if(n == 1){
        if(x == 0) return 0;
        if(x > 0) return min(x-1, (ll)3);
    } 
    if(x < a[n-1]+2) return f(n-1, x-1);
    if(x == a[n-1] + 2) return p[n-1]+1;
    if(x > a[n-1] + 2){
        return p[n-1]+1 + f(n-1, x - a[n-1] - 2);
    }
    return 0;
}

int main(){
    ll n, x;
    cin >> n >> x;
    p[0] = 1; a[0] = 1;
    rep(i, n + 3){
        p[i+1] = 2*p[i] + 1;
        a[i+1] = 2*a[i] + 3;
    }
    cout << f(n, x) << endl;
    return 0;
}