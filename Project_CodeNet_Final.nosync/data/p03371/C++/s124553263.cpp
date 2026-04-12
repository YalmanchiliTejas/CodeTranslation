#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b > c * 2)  {
        if (x > y)  {
            x -= y;
            if (a > 2 * c)  cout << 2 * c * y + x * 2 * c;
            else    cout <<  2 * c * y + x * a;
        }   else {
            y -= x;
            if (b > 2 * c)  cout << 2 * c * x + y * 2 * c;
            else    cout << 2 * c * x + y * b;
        }
    }   else    cout << a * x + b * y;
    return 0;
}