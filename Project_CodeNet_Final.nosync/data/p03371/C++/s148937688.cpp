#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int res = a * x + b * y;
    res = min(res, (c * 2) * max(x, y));
    res = min(res, min(x, y) * 2 * c + a * (x - min(x,y)) + b * (y - min(x, y)));
    cout << res << endl;
    return 0;
}