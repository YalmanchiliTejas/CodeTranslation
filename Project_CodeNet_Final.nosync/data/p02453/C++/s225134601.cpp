#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, t, q;
    vector<ll> v;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
    }
    cin >> q;
    for(ll i = 0; i < q; i++){
        cin >> t;
        printf("%lld\n", (int) (lower_bound(v.begin(), v.end(), t) - v.begin()));
    }
    return 0;
}
