#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main(){
    ll n; cin >> n;
    vector<ll> a(200000);
    ll dis = 1000000007;
    ll tmp=0;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        tmp += a[i];
    }

    ll ans =0;
    
    for(ll i=0; i<n; i++){
        tmp -= a[i];
        ans += (tmp%dis)*(a[i]%dis);
        ans = ans%dis; 
    }
    
    cout << ans << endl;
    return 0;
}