#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int m = 2 * max(x, y);
    long long min_cost = 1000000000000;
    for(int nab = 0; nab <= m; nab++) {
        long long cost = a * max(0, x - nab / 2) + b * max(0, y - nab / 2) + c * nab;
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;
}