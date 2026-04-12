#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (2*c <= a+b) {
        cout << 2 * min(x, y) * c + max((ll)0, (x - y)) * min(2*c, a) + max((ll)0, (y - x)) * min(2*c, b);
    } else {
        cout << x * a + y * b << endl;
    }
}
