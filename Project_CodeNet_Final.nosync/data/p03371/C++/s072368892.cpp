#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll cost;
    if (a+b >= 2*c) {
        cost = 2 * c * min(x, y);
        if (x > y) cost += (x - y) * a;
        else cost += (y - x) * b;
        cost = min(cost, (ll)2*c*max(x, y));
    } else {
        cost = a * x + b * y;
    }

    cout << cost << endl;

    return 0;
}