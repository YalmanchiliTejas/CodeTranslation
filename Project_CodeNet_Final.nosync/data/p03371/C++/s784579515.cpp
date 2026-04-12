#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    ll ans = 1LL << 60;
    for(int i = 0; i <= max(x, y) * 2; i+=2){
        ll sum = i * c;
        if(0 < x - i / 2) sum += ((x - i / 2) * a);
        if(0 < y - i / 2) sum += ((y - i / 2) * b);
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}
