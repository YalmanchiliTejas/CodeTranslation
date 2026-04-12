#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;


int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll mi = a * x + b * y;
    int X = x, Y = y;
    for (int i = 0; i <= max(X, Y) * 2; i += 2, x--, y--) {
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        mi = min(mi, (ll)(a * x + b * y + c * i));
    }
    cout << mi << endl;

    return 0;
}