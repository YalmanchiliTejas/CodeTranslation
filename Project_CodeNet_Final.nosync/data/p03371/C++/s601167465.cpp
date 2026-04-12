#include <iostream>
#include <algorithm>
#include <cinttypes>

using namespace std;

int main() {
    cin.sync_with_stdio(false);

    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    int minimal = INT32_MAX;
    for (int z = 0; z <= max(x, y)*2; z++) {
        int cost = z*c + max(0, (x - z/2)*a) + max(0, (y - z/2)*b);
        minimal = min(minimal, cost);
    }

    cout << minimal << endl;

    return 0;
}