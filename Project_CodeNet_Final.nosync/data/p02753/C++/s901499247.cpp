#include <iostream>
using namespace std;

int main() {
    char x, y, z;
    cin >> x >> y >> z;

    bool b = x != y || x != z || y != z;

    cout << (b ? "Yes" : "No");
    return 0;
}
