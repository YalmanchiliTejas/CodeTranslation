#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long ans = 0;
    if (x > y){
        ans = min({a * x + b * y, 2 * c * y + (x - y) * a, 2 * c * x});
    }
    else{
        ans = min({a * x + b * y, 2 * c * x + (y - x) * b, 2 * c * y});
    }

    cout << ans << endl;
    
    return 0;
}