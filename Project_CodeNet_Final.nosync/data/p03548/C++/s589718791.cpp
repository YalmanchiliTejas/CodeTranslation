#include <bits/stdc++.h>
using namespace std;


int main() {
    int64_t x, y, z;
    cin >> x >> y >> z;
    int64_t c = 0;
    x -= z;
    while (x >= y+z) {
        c++;
        x -= (y+z);
    }
    cout << c << endl;
    return 0;
}