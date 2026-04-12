#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    while(1){
        ll b[n] = {};
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            if(a[i] > n - 1) b[i] = (a[i] - (n - 1)) / n + !!((a[i] - (n - 1)) % n);
            sum += b[i];
        }
        if(!sum) break;
        for(ll i = 0; i < n; i++) a[i] = a[i] - b[i] * n + (sum - b[i]);
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}