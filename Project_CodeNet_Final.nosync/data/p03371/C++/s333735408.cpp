#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=2*c) {
        cout << a*x+b*y << endl;
    } else {
        int r = a*x+b*y;
        int lim = max(x, y);
        for(int i=min(x, y); i<=lim; i++) {
            r = min(r, a*max(x-i, 0) + b*max(y-i, 0) + c * 2 * i);
        }
        cout << r << endl;
    }
}
