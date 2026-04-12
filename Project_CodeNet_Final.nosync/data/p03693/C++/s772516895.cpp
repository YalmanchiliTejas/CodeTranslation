#include <iostream>

using namespace std;

int main() {
    int r, g, b; cin >> r >> g >> b;
    cout << (((g*2+b) % 4 == 0) ? "YES" : "NO") << endl;
    return 0;
}