#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, y, z;

    cin >> x >> y >> z;

    int ans = 1;
    while (true) {
        if (x < (z + (y + z) * ans)) {
            ans--;
            break;
        }
        ans++;
    }

    cout << ans << endl;
}