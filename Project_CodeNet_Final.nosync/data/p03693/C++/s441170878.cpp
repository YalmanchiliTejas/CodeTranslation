#include <iostream>
using namespace std;

int main() {
    short r, g, b;
    cin >> r >> g >> b;

    short target = 100*r + 10*g + b;
    if (target >= 4 && target % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
