#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = x;
    ll num = (x - a) / (a - b);
    num = max(num, 0ll);
    num = num % mod;
    ans += num * (b % mod);
    ans %= mod;
    //cout << ans <<" " <<  num << endl;
    x -= num * (a - b);
    if(x >= a) ans += b;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
