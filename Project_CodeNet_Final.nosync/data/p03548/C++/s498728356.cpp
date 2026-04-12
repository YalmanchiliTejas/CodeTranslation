#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
typedef long long ll;

int main() {

    int x, y, z; cin >> x >> y >> z;

    int x_a = x - 2 * z;

    if (x_a < y) {
        puts("0");
    } else {
        int ans = 0;

        int x_b = x_a - y;
        ++ans;

        ans += x_b / (y + z);

        cout << ans << endl;
    }
}