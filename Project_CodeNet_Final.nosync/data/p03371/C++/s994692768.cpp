#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (2*c <= a && 2*c <= b) {
        cout << 2 * max(x, y) * c << endl;
    } else if (2*c < a+b) {
        if(x>y)cout << 2 * min(x, y) * c + min(2*c*(x-y),(x - y) * a);
      	else cout << 2 * min(x, y) * c + min(2*c*(y-x),(y - x) * b);
    } else {
        cout << x * a + y * b << endl;
    }
}
