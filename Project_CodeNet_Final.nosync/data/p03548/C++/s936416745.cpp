#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int n = x / (y + z);
    if (x % (y + z) < z)
        --n;
    cout << n << '\n';
}
