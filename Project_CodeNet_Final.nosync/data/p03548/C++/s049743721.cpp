#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int i;
    for (i = 0; ; i++) {
        if ((i + 1) * z + y * i > x) break;
    }
    cout << i - 1 << endl;
    return 0;
}
