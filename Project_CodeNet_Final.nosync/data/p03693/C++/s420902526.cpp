#include <iostream>
using namespace std;

int main(void) {
    int r, g, b;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> r >> g >> b;
    cout << ((r * 100 + g * 10 + b) % 4 == 0? "YES" : "NO") << "\n";
    return 0;
}