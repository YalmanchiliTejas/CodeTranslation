#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int ans = x / (y + z);
    if (x % (y + z) < z) ans--;

    cout << ans << endl;
    return 0;
}
