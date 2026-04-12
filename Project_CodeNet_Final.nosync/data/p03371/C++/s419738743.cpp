#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll powk(ll a, ll n){
    ll r = 1;
    for(ll i = 0;i < n;i++){
        r *= a;
    }

    return r;
}

int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if(a + b > 2 * c){
        ll t = 0;
        if(x < y){
            t = (y - x) * b;
        }
        else{
            t = (x - y) * a;
        }
        cout << min(min(x, y) * c * 2 + t, max(x, y) * c * 2);
    }
    else{
        cout << x * a + y * b;
    }

    return 0;
}