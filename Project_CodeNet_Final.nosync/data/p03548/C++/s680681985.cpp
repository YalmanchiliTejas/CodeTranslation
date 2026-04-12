#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int ans = 1;
    x -= (y + z + z);

    while (x - y - z >= 0) {
        x -= (y + z);
        ans++;
    }

    cout << ans << endl;

    return 0;
}
