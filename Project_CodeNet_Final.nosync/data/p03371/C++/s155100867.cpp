#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll total = 0;
    total += min(a + b, 2 * c) * min(x, y);
    if(x == max(x, y)){
        x -= min(x,y);
        total += x * min(a, 2 * c);
    }
    else{
        y -= min(x,y);
        total += y * min(b, 2 * c);
    }
    cout << total;
}