#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    x -= z;
    for (int i = x; i >= (y+z);) {
        i -= (y+z);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
