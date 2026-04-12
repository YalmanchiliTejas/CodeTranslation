#include <iostream>

using namespace std;
int main() {
    char r, g, b;
    cin >> r >> g >> b;

    int n = (r - '0') * 100 + (g - '0') * 10 + (b - '0');
    cout << (n % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}