#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    // not buy ab pizza;
    ll cost = a * x + b * y;
    ll z = 0;
    for (ll i = 2; i < 2*(x+y); ){
        ll k = max(z, (x - i/2)) * a + max(z, (y - i/2)) * b + i * c;
        cost = min(cost, k);
        i += 2;
    }
    cout << cost << endl;
}