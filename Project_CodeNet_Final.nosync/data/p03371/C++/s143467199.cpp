#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    cout << min(x, y) * min(2 * c, a + b) + abs(x - y) * min(2 * c, x > y ? a : b) << endl;
}
