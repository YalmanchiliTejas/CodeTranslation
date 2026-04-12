#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if(a + b <= 2 * c) {
        cout << a * x + b * y << endl;
    }
    else {
        if(x >= y) {
            if(a <= 2 * c) {
                cout << 2 * c * y + a * (x - y);
            }
            else cout << 2 * c * x << endl;
        }
        else {
            if(b <= 2 * c) {
                cout << 2 * c * x + b * (y - x);
            }
            else cout << 2 * c * y << endl;
        }
    }
    return 0;
}