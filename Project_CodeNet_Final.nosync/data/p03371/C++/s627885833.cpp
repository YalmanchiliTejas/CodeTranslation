#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int a, b, c, x, y;
    ll price = 0;
    cin >> a >> b >> c >> x >> y;
    ll which = (a + b) * min(x, y);
    if (which > c * 2 * min(x, y)) {
        price = c * 2 * min(x, y);
        if (x > y)price += a * (x - y);
        else if (y > x)price += b * (y - x);
        if (price > (c * 2 * max(x, y)))cout << c * 2 * max(x, y) << endl;
        else cout << price << endl;
    }
    else {
        cout << a * x + b * y << endl;
    }
}