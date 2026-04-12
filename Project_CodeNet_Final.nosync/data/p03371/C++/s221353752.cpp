#include <string.h>
#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int price = 0;
    if ((a + b) > (c * 2)) {
        int setp = min(x, y);
        price += c * (setp * 2);
        x -= setp;
        y -= setp;
    }
    price += a > (c * 2) ? x * (c * 2) : x * a;
    price += b > (c * 2) ? y * (c * 2) : y * b;

    cout << price << endl;
}