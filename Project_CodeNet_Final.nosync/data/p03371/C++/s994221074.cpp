#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;
    vector<ll> pizza = {x, y, 0};
    ll ans = 1001001001001001001;
    for (int i = 0; i < max(x, y) + 1; ++i) {
        ans = min(ans, a * pizza[0] + b * pizza[1] + c * pizza[2]);
        if (pizza[0] != 0) pizza[0]--;
        if (pizza[1] != 0) pizza[1]--;
        pizza[2]++;
    }
    cout << ans << endl;
}
