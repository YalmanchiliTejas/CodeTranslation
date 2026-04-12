#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll z = min(x,y);

    cout << min(a *x + b *y, min(c * max(x,y) * 2,  c * z * 2 + ((x>y)?a:b) * abs(x-y))) << endl;
}
