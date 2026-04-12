#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int i, sum;

    i = 0;
    sum = z;
    while (sum <= x) {
        sum += y + z;
        ++i;
    }
    cout << i - 1 << endl;

    return 0;
}
