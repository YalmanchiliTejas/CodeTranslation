#include <bits/stdc++.h>

using namespace std;

int main() {
    int x = 0, y = 0, z = 0, ans = 0;
    cin >> x >> y >> z;

    while (x >= y + z + z) {

        ans++;
        x -= (y + z);

    }
    cout << ans << endl;
    return 0;
}