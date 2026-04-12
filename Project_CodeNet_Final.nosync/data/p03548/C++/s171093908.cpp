#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int x, y, z;
    int cnt = 0;

    cin >> x >> y >> z;

    x -= z;
    while (x >= y + z) {
        x -= y + z;
        cnt++;
    }

    cout << cnt;
}
