#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0;i < n;i++) cin >> a[i];
    
    ll q;
    cin >> q;
    
    for(ll i = 0;i < q;i++){
        ll k;
        cin >> k;
        
        cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
    }
}
