#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int num = x / (y + z);
    int space = num * (y + z);

    if (space + z <= x) {
        cout << num << endl;
    } else {
        cout << num - 1 << endl;
    }

    return 0;
}