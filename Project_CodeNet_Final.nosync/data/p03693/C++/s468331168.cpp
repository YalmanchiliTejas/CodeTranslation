// RGB Cards
#include <iostream>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int total_rgb = 100*r + 10*g + b;
    if (total_rgb % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}