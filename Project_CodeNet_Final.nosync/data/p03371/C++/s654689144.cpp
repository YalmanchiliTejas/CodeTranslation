#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 200000000000;
    for(int i = 0; i <= 200000; i+=2) {
        ll cost = c * i;
        cost += max(0, x - (i / 2)) * a;
        cost += max(0, y - (i / 2)) * b;
        ans = min(ans, cost);
    }
    cout << ans << endl;

    return 0;
}

