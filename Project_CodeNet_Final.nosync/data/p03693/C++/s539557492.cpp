#include <iostream>
using namespace std;

int main() {
    int r, b, g;
    cin >> r >> b >> g;
    int a = r * 100 + b * 10 + g;
    if (a % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}