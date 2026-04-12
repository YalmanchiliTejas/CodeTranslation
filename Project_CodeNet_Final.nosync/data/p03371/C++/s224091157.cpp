#include <iostream>

using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (a + b <= 2 * c) cout << a * x + b * y << endl;
    else{
        int v1 = 2 * c * min(x, y) + abs(x - y) * (x > y?a:b);
        int v2 = 2 * c * max(x, y);
        cout << min(v1, v2) << endl;
    }
}