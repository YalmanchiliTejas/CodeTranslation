#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int ans;
    ans = (x - z) / (y + z);

    cout << ans << endl;

    return 0;
}
