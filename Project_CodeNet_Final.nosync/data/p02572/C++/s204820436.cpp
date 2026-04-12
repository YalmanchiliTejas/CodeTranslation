#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
    ll n;
    cin >> n;
    ll total = 0;
    ll minus = 0;
    for(int i = 0; i < n; i++){
        ll in;
        cin >> in;
        total = (total + in) % mod;
        minus = (minus + in * in) % mod;
    }
    ll ans = (total * total - minus + mod) % mod;
    if(ans % 2) cout << (ans + mod) / 2 << "\n";
    else cout << ans / 2 << "\n"; 
}