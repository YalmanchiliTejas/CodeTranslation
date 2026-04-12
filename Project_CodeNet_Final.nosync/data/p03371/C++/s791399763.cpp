#include <iostream>

using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (y < x) {
        swap(x, y);
        swap(a, b);
    }
    int pa = c * x * 2 + b * (y - x), pb = a * x + b * y, pc = c * y * 2;
    int min = pa;
    if (pb < min) min = pb;
    if (pc < min) min = pc;
    cout << min << endl;
    return 0;
}
