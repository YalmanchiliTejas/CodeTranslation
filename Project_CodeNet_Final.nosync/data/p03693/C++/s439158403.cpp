#include <iostream>
using namespace std;

int main() {
    int r, b, g;
    cin >> r >> b >> g;
    if ((10*b+g) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}