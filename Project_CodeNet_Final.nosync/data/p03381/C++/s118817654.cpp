#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll n;
    cin >> n;
    ll x[n];
    ll y[n];
    for(ll i = 0; i < n; i++) cin >> x[i];
    for(ll i = 0; i < n; i++) y[i] = x[i];
    sort(x, x + n);
    ll cen = x[n / 2 - 1];
    for(ll i = 0; i < n; i++) cout << x[n / 2 - 1 + (y[i] > cen ? 0 : 1)] << endl;
    return 0;
}