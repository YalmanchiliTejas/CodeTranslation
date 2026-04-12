#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    
    ll x, y, z;
    cin >> x >> y >> z;
    ll ans = 0;
    for(ll i = 1; i <= x; i++){
        ll l = y * i + z * (i + 1);
        if(l <= x)ans = max(ans, i);
    }
    cout << ans << endl;
    
    return 0;
}
